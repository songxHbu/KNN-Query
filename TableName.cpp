// TableName.cpp : implementation file
//

#include "stdafx.h"
#include "LearnIing6.h"
#include "TableName.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTableName dialog


CTableName::CTableName(CWnd* pParent /*=NULL*/)
	: CDialog(CTableName::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTableName)
	m_DataSetTable = _T("");
	m_TableName = _T("");
	m_OutputTableName = _T("");
	m_WorkloadTable = _T("");
	m_TopN = TOP_N; //20 ; //100;  //20; 100
	//}}AFX_DATA_INIT
}


void CTableName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTableName)
	DDX_CBString(pDX, IDC_COMBO_DATASET, m_DataSetTable);
	DDX_CBString(pDX, IDC_COMBO_INPUT_TABLE, m_TableName);
	DDX_CBString(pDX, IDC_COMBO_OUTPUT_TABLE, m_OutputTableName);
	DDX_CBString(pDX, IDC_COMBO_WORKLOAD, m_WorkloadTable);
	DDX_Text(pDX, IDC_EDIT_TOPN, m_TopN);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTableName, CDialog)
	//{{AFX_MSG_MAP(CTableName)
	//}}AFX_MSG_MAP
	//ON_BN_CLICKED(IDOK, &CTableName::OnBnClickedOk)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTableName message handlers

void CTableName::OnOK() 
{
	// TODO: Add extra validation here
	/////////////////////////////
	UpdateData(true);

	CLearnIing6App * pApp = (CLearnIing6App * ) AfxGetApp();
  
	for(int i = 0; i<1024; i++)
	{
		pApp->TableName[i]        =0;
		pApp->szInputTableName[i] =0;
		pApp->szOutputTableName[i]=0;
	}
	strcpy( pApp->TableName , m_DataSetTable); // 
	strcpy( pApp->szInputTableName , m_TableName); // 
	strcpy( pApp->szOutputTableName , m_OutputTableName); // 
	
	pApp->m_WorkloadTable = m_WorkloadTable;
    pApp->m_TopN =  m_TopN;
    //pApp->m = m_Num_Query;
	 
	//////////////////////////////

	CDialog::OnOK();
}

BOOL CTableName::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//1. DataSet Tables
	CComboBox * pComboDataSet = (CComboBox *) GetDlgItem(IDC_COMBO_DATASET);
	
	/***  
	//pComboDataSet->AddString("Attr_Census2D");
	//pComboDataSet->AddString("Attr_Census3D");
	//pComboDataSet->AddString("Attr_Array3D");
	//pComboDataSet->AddString("Attr_Gauss3D");
	//pComboDataSet->AddString("Attr_Cover4D");
    ***/

    // only for high-dim, N = 20, 10, 80, 200
    // N = 20, // already OK 
    // N =  10, 80, 200 

	//pComboDataSet->AddString("Lsi_025D");
	//pComboDataSet->AddString("Lsi_050D"); //by song 2015.6.30
	//pComboDataSet->AddString("Lsi_104D"); //by song 2015.6.30
	pComboDataSet->AddString("SIFT");
	pComboDataSet->AddString("Lsi_025D");
	pComboDataSet->AddString("Lsi_050D"); //by song 2015.6.30
	pComboDataSet->AddString("Lsi_104D"); //by song 2015.6.30

	pComboDataSet->SetCurSel(3);

	//2. Input Tables (KB Profile Tables) 
	CComboBox * pComboInputTable = (CComboBox *) GetDlgItem(IDC_COMBO_INPUT_TABLE);
	
	////pComboInputTable->AddString("Census2D_Top100_Profile2000_LRC1");
	////pComboInputTable->AddString("Census3D_Top100_Profile2000_LRC1");
	////pComboInputTable->AddString("Array3D_Top100_Profile2000_LRC1");
	////pComboInputTable->AddString("Gauss3D_Top100_Profile2000_LRC1");
	////pComboInputTable->AddString("Cover4D_Top100_Profile2000_LRC1");

	//pComboInputTable->AddString("Lsi_025D_Top200_Profile2000_LRC1");
	//pComboInputTable->AddString("Lsi_025D_Top80_Profile2000_LRC1");
	//pComboInputTable->AddString("Lsi_025D_Top10_Profile2000_LRC1");

	//pComboInputTable->AddString("Lsi_050D_Top200_Profile2000_LRC1");
	//pComboInputTable->AddString("Lsi_050D_Top80_Profile2000_LRC1");
	//pComboInputTable->AddString("Lsi_050D_Top10_Profile2000_LRC1");

	//pComboInputTable->AddString("Lsi_104D_Top200_Profile2000_LRC1");
	//pComboInputTable->AddString("Lsi_104D_Top80_Profile2000_LRC1");
	//pComboInputTable->AddString("Lsi_104D_Top10_Profile2000_LRC1"); //by song 2015.6.30


	//pComboInputTable->AddString("Lsi_025D_Top20_Profile2000_LRC1");
	//pComboInputTable->AddString("Lsi_050D_Top20_Profile2000_LRC1"); //by song 2015.6.30
	//pComboInputTable->AddString("Lsi_104D_Top20_Profile2000_LRC1");
	pComboInputTable->AddString("SIFT_Top20_Profile2000");
	pComboInputTable->AddString("Lsi_025D_Top20_Profile2000_LRC1");
	pComboInputTable->AddString("Lsi_050D_Top20_Profile2000_LRC1"); //by song 2015.6.30
	pComboInputTable->AddString("Lsi_104D_Top20_Profile2000_LRC");


	pComboInputTable->SetCurSel(3);

	//3. Output Tables (Insert Tables // that are our results)
	CComboBox * pComboOutputTable = (CComboBox *) GetDlgItem(IDC_COMBO_OUTPUT_TABLE);

	//pComboOutputTable->AddString("Census2D_T0100_B_Learning_F_W10000_LRC1");
	//pComboOutputTable->AddString("Census3D_T0100_B_Learning_F_W10000_LRC1");
	//pComboOutputTable->AddString("Array3D_T0100_B_Learning_F_W10000_LRC1");
	//pComboOutputTable->AddString("Gauss3D_T0100_B_Learning_F_W10000_LRC1");
	//pComboOutputTable->AddString("Cover4D_T0100_B_Learning_F_W10000_LRC1");

	//pComboOutputTable->AddString("Lsi_025D_T00200_B_Learning_F_W10000_LRC1");
	//pComboOutputTable->AddString("Lsi_025D_T0080_B_Learning_F_W10000_LRC1");
	//pComboOutputTable->AddString("Lsi_025D_T0010_B_Learning_F_W10000_LRC1");

	//pComboOutputTable->AddString("Lsi_050D_T00200_B_Learning_F_W10000_LRC1");
    //pComboOutputTable->AddString("Lsi_050D_T0080_B_Learning_F_W10000_LRC1");
	//pComboOutputTable->AddString("Lsi_050D_T0010_B_Learning_F_W10000_LRC1");

	//pComboOutputTable->AddString("Lsi_104D_T00200_B_Learning_F_W10000_LRC1");
    //pComboOutputTable->AddString("Lsi_104D_T0080_B_Learning_F_W10000_LRC1");
	//pComboOutputTable->AddString("Lsi_104D_T0010_B_Learning_F_W10000_LRC1");  //by song 2015.6.30

	//pComboOutputTable->AddString("Lsi_025D_T0020_B_Learning_F_W10000_LRC1");
	//pComboOutputTable->AddString("Lsi_050D_T0020_B_Learning_F_W10000_LRC1"); //by song 2015.6.30
	//pComboOutputTable->AddString("Lsi_104D_T0020_B_Learning_F_W10000_LRC1");
	pComboOutputTable->AddString("SIFT_Top20_Learning_F_W10000");
	pComboOutputTable->AddString("Lsi_025D_T0020_B_Learning_F_W10000_LRC1");
	pComboOutputTable->AddString("Lsi_050D_T0020_B_Learning_F_W10000_LRC1"); //by song 2015.6.30
	pComboOutputTable->AddString("Lsi_104D_T0020_B_Learning_F_W10000_LRC1");

	pComboOutputTable->SetCurSel(3);

	//4. Workload Tables 
	// have 10000 queries
	CComboBox * pComboWorkload = (CComboBox *) GetDlgItem(IDC_COMBO_WORKLOAD);
	
	////pComboWorkload->AddString("Census2D_B_WorkLoad");
	////pComboWorkload->AddString("Census3D_B_WorkLoad");
	////pComboWorkload->AddString("Array3D_B_WorkLoad");
	////pComboWorkload->AddString("Gauss3D_B_WorkLoad");
	////pComboWorkload->AddString("Cover4D_B_WorkLoad");


	//pComboWorkload->AddString("Lsi_025D_B_WorkLoad");
	//pComboWorkload->AddString("Lsi_050D_B_WorkLoad"); // by song 2015.6.30
	//pComboWorkload->AddString("Lsi_104D_B_WorkLoad");//by song 2015.6.30
	pComboWorkload->AddString("SIFT_WorkLoad");
	pComboWorkload->AddString("Lsi_025D_B_WorkLoad1_2");
	pComboWorkload->AddString("Lsi_050D_B_WorkLoad2"); // by song 2015.6.30
	pComboWorkload->AddString("Lsi_104D_B_WorkLoad2");//by song 2015.6.30

	pComboWorkload->SetCurSel(3);
 /////////////////////// body end ///////////////////////////////////
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CTableName::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialog::OnOK();
}
