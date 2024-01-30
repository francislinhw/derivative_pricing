// ExcelDriver.cpp
//
// Excel driver class.
//
// Datasim Education BV (c) 2003
// 
// Modification dates:
// 23 July 2003 - MB - Started.
// 29 July 2003 - MB - Added support for PropertySets.
//					 - Writing chart data in vertical direction.
//					 - Added Instance() method which returns an ExcelDriver singleton.
// 2005-10-16 DD Now to be changed for Intro C++ book
// 2005-12-1 DD hpp and cpp versions
// 2005-12-9 DD creatVector here
// 2005-12-10 DD MAJOR BUG FIXED, thanks to Martin Nisbit. Here is a 
// description of problem: 
// 2005-12-16 DD No exception at this level (AddMatrix)
// 2009-1-12 DD print matrix with sets as indices
// 2012-2-23 DD std::vector now (no matrices)
// 2013-10-28 Excel::_WorksheetPtr pSheet = pWorkbook->Worksheets->GetItem("Sheet1");
// Excel::_WorksheetPtr pSheet = pWorkbook->Worksheets->GetItem(1);
//
/*
	Getting the Excel Driver to work is not quite trivial, and is covered on its own page. If you compile it successfully under Office XP or Office 2003, but get a "type mismatch" runtime error instead of results when trying to run it, you need to use this version instead. As Martin Nisbit (who provided that version) discovered, one has to replace all occurrences of "something.Value" by "Something.Value2" for the driver to work under these versions of Office, so for example instead of 
	item->Value = label.c_str();
	you have to use 
	item->Value2 = label.c_str();
	Also, the Excel Driver, even when it runs successfully, tends to crash upon exit - happened to me both when using Office 2000 and Office 2003, and Martin reports the same behavior under Office XP. When I will figure out what causes it, I'll write it here - or if you know, please write me!

*/
//
// (C) Datasim Education BV 2003 - 2012
//

#ifndef ExcelDriver_CPP
#define ExcelDriver_CPP

#include "UtilitiesDJD/ExcelDriver/ExcelDriver.hpp"
#include "UtilitiesDJD/BitsAndPieces/StringConversions.hpp"

// Writes label and vector to cells in horizontal direction.
void ExcelDriver::ToSheetHorizontal( Excel::_WorksheetPtr sheet, 
					long sheetRow, long sheetColumn,
					const std::string& label, const std::vector<double> & values )
{
		// Get cells.
		Excel::RangePtr pRange=sheet->Cells;
	
		// First cell contains the label.
		Excel::RangePtr item = pRange->Item[sheetRow][sheetColumn];
	//	item->Value = label.c_str();
		item->Value2 = label.c_str();
	
		sheetColumn++;

		// Next cells contain the values.
		for(long i= 0; i < values.size(); i++)
		{
			Excel::RangePtr item = pRange->Item[sheetRow][sheetColumn];
//			item->Value = values[i];			
			item->Value2 = values[i];			
	
			sheetColumn++;
		}
}

// Writes label and vector to cells in vertical direction.
void ExcelDriver::ToSheetVertical( Excel::_WorksheetPtr sheet,
					long sheetRow, long sheetColumn,
					const std::string& label, const std::vector<double> & values )
{
		// Get cells.
		Excel::RangePtr pRange=sheet->Cells;
	
		// First cell contains the label.
		Excel::RangePtr item = pRange->Item[sheetRow][sheetColumn];
		// item->Value = label.c_str();
		item->Value2 = label.c_str();
	
		sheetRow++;

		// Next cells contain the values.
		for(int i=0; i < values.size(); i++)
		{
			Excel::RangePtr item = pRange->Item[sheetRow][sheetColumn];
			//item->Value = values[i];			
			item->Value2 = values[i];
			sheetRow++;
		}
}

// Throw COM error as string.
void ExcelDriver::ThrowAsString( _com_error & error )
{
		bstr_t description = error.Description();
		if( !description )
		{
			description = error.ErrorMessage();
		}

		throw string(description);
}

// Constructor. Starts Excel in invisible mode.
ExcelDriver::ExcelDriver()	: curDataColumn(1)
{
		try
		{
			// Initialize COM Runtime Libraries.
			CoInitialize(NULL);

			// Start excel application.
			xl.CreateInstance(L"Excel.Application");
			xl->Workbooks->Add((long) Excel::xlWorksheet);
          //  xl->Workbooks->OpenFile("D:\Documents and Settings\dduffy\My Documents\Testje.xls");

			// Rename "Sheet1" to "Chart Data".
			Excel::_WorkbookPtr pWorkbook = xl->ActiveWorkbook;
			//Excel::_WorksheetPtr pSheet = pWorkbook->Worksheets->GetItem("Sheet1");
			Excel::_WorksheetPtr pSheet = pWorkbook->Worksheets->GetItem(1);
			pSheet->Name = "Chart Data";
		}
		catch( _com_error & error )
		{
			ThrowAsString(error);
		}
}

// Destructor.
ExcelDriver::~ExcelDriver()
{
		// Undo initialization of COM Runtime Libraries.
		CoUninitialize();
	}

	// Access to single, shared instance of ExcelDriver (singleton).
ExcelDriver& ExcelDriver::Instance()
{
		static ExcelDriver singleton;
		return singleton;
}

// Create chart with a number of functions. The arguments are:
//  x:			vector with input values
//  labels:		labels for output values
//  vectorList: list of vectors with output values.
//  chartTitle:	title of chart
//  xTitle:		label of x axis
//  yTitle:		label of y axis
void ExcelDriver::CreateChart(const std::vector<double> & x, const list<std::string> & labels, const list<std::vector<double> > & vectorList, 
					const std::string& chartTitle, const std::string& xTitle, const std::string& yTitle)
{
		try
		{
			// Check # labels vs. # vectors.
			if( labels.size() != vectorList.size() )
			{
				throw "Number of labels must equal number of vectors.";
			}

			// Activate sheet with numbers.
			Excel::_WorkbookPtr pWorkbook = xl->ActiveWorkbook;
			Excel::_WorksheetPtr pSheet = pWorkbook->Worksheets->GetItem("Chart Data");
			
			// Calculate range with source data.
			// The first row contains the labels shown in the chart's legend.
			long beginRow = 1;
			long beginColumn = curDataColumn;
			long endRow = x.size() + 1;								// +1 to include labels.
			long endColumn = beginColumn + vectorList.size();		// 1st is input, rest is output.

			// Write label + input values to cells in vertical direction.
			ToSheetVertical(pSheet, 1, curDataColumn, xTitle, x);		// X values.
			curDataColumn++;

			// Write label + output values to cells in vertical direction.
			list<std::vector<double> >::const_iterator vectorIt;
			list<std::string>::const_iterator labelIt = labels.begin();
			for( vectorIt = vectorList.begin(); vectorIt != vectorList.end(); vectorIt++ )
			{
				// Get label and row index.
				string label = *labelIt;
				
				// Add label + output values to Excel.
				ToSheetVertical(pSheet, 1, curDataColumn, label, *vectorIt);

				// Advance row and label.
				curDataColumn++;
				labelIt++;
		}			
			
			// Create range objects for source data.
			Excel::RangePtr pBeginRange = pSheet->Cells->Item[beginRow][beginColumn];
			Excel::RangePtr pEndRange = pSheet->Cells->Item[endRow][endColumn];
			Excel::RangePtr pTotalRange = pSheet->Range[(Excel::Range*)pBeginRange][(Excel::Range*)pEndRange];
			
			// Create the chart and sets its type
			Excel::_ChartPtr pChart=xl->ActiveWorkbook->Charts->Add();
			pChart->ChartWizard((Excel::Range*)pTotalRange, (long)Excel::xlXYScatter, 6L, (long)Excel::xlColumns, 1L, 1L, true, chartTitle.c_str(), xTitle.c_str(), yTitle.c_str());
			pChart->ApplyCustomType(Excel::xlXYScatterSmooth);
			pChart->Name = chartTitle.c_str();

			// Make all titles visible again. They were erased by the ApplyCustomType method.
			pChart->HasTitle=true;
			pChart->ChartTitle->Text=chartTitle.c_str();

			Excel::AxisPtr pAxis = pChart->Axes((long)Excel::xlValue, Excel::xlPrimary);
			pAxis->HasTitle = true;
			pAxis->AxisTitle->Text = yTitle.c_str();
			
			pAxis=pChart->Axes((long)Excel::xlCategory, Excel::xlPrimary);
			pAxis->HasTitle = true;
			pAxis->AxisTitle->Text = xTitle.c_str();

			// Add extra row space to make sheet more readable.
			curDataColumn++;
		}
		catch( _com_error & error )
		{
			ThrowAsString(error);
		}
}

    // Create chart with a number of functions. The arguments are:
	//  x:			vector with input values
	//  y:			vector with output values.
	//  chartTitle:	title of chart
	//  xTitle:		label of x axis
	//  yTitle:		label of y axis
void ExcelDriver::CreateChart(const std::vector<double> & x, const std::vector<double> & y, const std::string& chartTitle, 
							  const std::string& xTitle, const std::string& yTitle)
{ 
		// Create list with single function and single label.
		list<std::vector<double> > functions;
		list<string> labels;
		functions.push_back(y);
		labels.push_back(chartTitle);
		CreateChart(x, labels, functions, chartTitle, xTitle, yTitle);
	}




// Make Excel window visible.
void ExcelDriver::MakeVisible( bool b)
{
		// Make excel visible.
		xl->Visible = b ? VARIANT_TRUE : VARIANT_FALSE;
}


// For debugging, for example
void ExcelDriver::printStringInExcel(const string& s, long rowNumber, long colNumber,
					const string& sheetName	)
{ // Mainly for debugging

		// Add sheet.
		Excel::_WorkbookPtr pWorkbook = xl->ActiveWorkbook;
		Excel::_WorksheetPtr pSheet = pWorkbook->Worksheets->Add();
		pSheet->Name = sheetName.c_str();

		// Add properties to cells.
		Excel::RangePtr pRange = pSheet->Cells;
		pRange->Item[rowNumber][colNumber] = s.c_str();
}

void ExcelDriver::printStringInExcel(const list<string>& s, long startRow, long colNumber,
					const string& sheetName	)
{ // Mainly for debugging

		// Add sheet.
		Excel::_WorkbookPtr pWorkbook = xl->ActiveWorkbook;
		Excel::_WorksheetPtr pSheet = pWorkbook->Worksheets->Add();
//		pSheet->Name = sheetName.c_str();

		Excel::RangePtr pRange = pSheet->Cells;
	
		list<string>::const_iterator it;

		for (it = s.begin(); it != s.end(); it++)
		{
				
			pRange->Item[startRow][colNumber] = (*it).c_str();
			startRow++;
		}

}

#endif
