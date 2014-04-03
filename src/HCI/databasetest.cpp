

#include <stdio.h>
#include <iostream>
#include <comdef.h>
#include <conio.h>
#include "Database.h"

char CnnStr[200]="Server=tcp:l2ud2zp8th.database.windows.net,1433;Database=HCI_PROJECT;UserID=sqluser@l2ud2zp8th;Password=12curING*$;Trusted_Connection=False;Encrypt=True;Connection Timeout=30;";

char ErrStr[200];

int main()
{
	::CoInitialize(NULL);
	Database db;
	Table tbl;
	if(!db.Open("sqluser","12curLING*$",CnnStr))
	{
		db.GetErrorErrStr(ErrStr);
		cout<<ErrStr<<"\n";
	}
	if(!db.Execute("select * from InputStrings",tbl))
	{
		db.GetErrorErrStr(ErrStr);
		cout<<ErrStr<<"\n";
	}
	/*if(!db.OpenTbl(ADODB::adCmdText,"select * from InputStrings",tbl))
	{
		db.GetErrorErrStr(ErrStr);
		cout<<ErrStr<<"\n";
	}*/
	char id[100];
	if(!tbl.ISEOF())
		tbl.MoveFirst();
	
	while(!tbl.ISEOF())
	{
		if(tbl.Get("ID",id))
			cout<<"\nID:"<<id;
		else
		{
			tbl.GetErrorErrStr(ErrStr);
			cout<<"\n"<<ErrStr<<"\n";
			break;
		}
		if(tbl.Get("text",id))
			cout<<" text:"<<id;
		else
		{
			tbl.GetErrorErrStr(ErrStr);
			cout<<"\n"<<ErrStr<<"\n";
			break;
		}

		tbl.MoveNext();
	}
	::CoUninitialize();
	return 0;
}