#include <ql/quantlib.hpp>
#include <iostream>

using namespace QuantLib;

int main() {
    // 設定評估日期
    Date todaysDate(15, May, 2022);
    Date settlementDate(17, May, 2022);
    Settings::instance().evaluationDate() = todaysDate;

    // 選擇市場參數
    Option::Type type(Option::Put);
    Real underlying = 100;
    Real strike = 100;
    Spread dividendYield = 0.02;
    Rate riskFreeRate = 0.01;
    Volatility volatility = 0.20;

    Date maturity(15, May, 2023);
    DayCounter dayCounter = Actual365Fixed();

    // 定義雙重無接觸障礙
    DoubleBarrier::Type barrierType = DoubleBarrier::KnockOut;
    Real lowerBarrier = 95.0;
    Real upperBarrier = 105.0;
    Real rebate = 0.0;

    std::cout << "Double No-Touch option pricing using QuantLib" << std::endl;

    // 構建選擇權的障礙
    ext::shared_ptr<StrikedTypePayoff> payoff(new PlainVanillaPayoff(type, strike));
    ext::shared_ptr<Exercise> exercise(new EuropeanExercise(maturity));

    Handle<Quote> underlyingH(ext::make_shared<SimpleQuote>(underlying));
    Handle<YieldTermStructure> flatTermStructure(ext::make_shared<FlatForward>(settlementDate, riskFreeRate, dayCounter));
    Handle<YieldTermStructure> flatDividendTS(ext::make_shared<FlatForward>(settlementDate, dividendYield, dayCounter));
    Handle<BlackVolTermStructure> flatVolTS(ext::make_shared<BlackConstantVol>(settlementDate, Calendar(), volatility, dayCounter));

    ext::shared_ptr<BlackScholesMertonProcess> bsmProcess(new BlackScholesMertonProcess(underlyingH, flatDividendTS, flatTermStructure, flatVolTS));

    // 定義雙重無接觸選擇權
    DoubleBarrierOption doubleBarrierOption(barrierType, lowerBarrier, upperBarrier, rebate, payoff, exercise);

    // 計算定價
    doubleBarrierOption.setPricingEngine(ext::make_shared<AnalyticBarrierEngine>(bsmProcess));

    // 輸出結果
    std::cout << "Double No-Touch Option NPV: " << doubleBarrierOption.NPV() << std::endl;

    return 0;
}
