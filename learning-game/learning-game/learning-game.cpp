#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const double INFINITE = 1000;
double x, y, pminx = INFINITE, pminy = INFINITE, pmaxx = 0, pmaxy = 0, nminx = 0, nminy = 0, nmaxx = INFINITE, nmaxy = INFINITE;
int mode, label; //label:正例は1,負例は0;

int main(){
//学習時
	cout << "長方形学習ゲーム" <<endl;
	cout << "x座標, y座標, 正例か負例かの順に入力してください" <<endl;
	cout << "x, yには1000以下の正の実数を入力し, 正例は1, 負例は0で表してください" <<endl;
	cout << "ex) 2.2 4.8 1" <<endl;
	cout << "学習を終了したい場合は負の数を入れてください" <<endl;
	ifstream ifs;
	ifs.open("test.txt");
	while(1){ 
		ifs >> x >> y >> label;
		//cout << x << " " << y << " " << label << endl;

		if(x < 0 || y < 0 || (label != 0 && label != 1)) break;
		if(label == 1){	
			if(x < pminx) pminx = x;
			if(x > pmaxx) pmaxx = x;
			if(y < pminy) pminy = y;
			if(y > pmaxy) pmaxy = y;
		}
	}
	ifs.close();
	ifs.open("test.txt");
	while(1){
		ifs >> x >> y >> label;
		if(x < 0 || y < 0 || (label != 0 && label != 1)) break;
		if(label == 0){
			if(x < pminx && x > nminx) nminx = x;
			if(x > pmaxx && x < nmaxx) nmaxx = x;
			if(y < pminy && y > nminy) nminy = y;
			if(y > pmaxy && y < nmaxy) nmaxy = y;
		}
	}
	ifs.close();
	ofstream ofs;
	ofs.open( "result.txt" );
	ofs << "pminx = " << pminx << endl;
	ofs << "pminy = " << pminy << endl;
	ofs << "pmaxx = " << pmaxx << endl;
	ofs << "pmaxy = " << pmaxy << endl;
	ofs << "nminx = " << nminx << endl;
	ofs << "nminy = " << nminy << endl;
	ofs << "nmaxx = " << nmaxx << endl;
	ofs << "nmaxy = " << nmaxy << endl;
	ofs.close();

//学習結果の披露
	cout << "学習結果を披露します" <<endl;
	cout << "pminx = " << pminx << endl;
	cout << "pminy = " << pminy << endl;
	cout << "pmaxx = " << pmaxx << endl;
	cout << "pmaxy = " << pmaxy << endl;
	cout << "nminx = " << nminx << endl;
	cout << "nminy = " << nminy << endl;
	cout << "nmaxx = " << nmaxx << endl;
	cout << "nmaxy = " << nmaxy << endl;
	cout << "全ての正例に対して間違わない場合は0を" <<endl;
	cout << "全ての負例に対して間違わない場合は1を入力してください" <<endl;
	while(1){
		cin >> mode;
		if(mode ==0 || mode == 1) break;
		else cout << "正しく入力してください" <<endl;
	}
	if(mode == 0) cout << "正例に対して必ず正しいラベルを返します" <<endl;
	if(mode == 1) cout << "負例に対して必ず正しいラベルを返します" <<endl;
	cout << "x座標, y座標の順に入力してください" <<endl;
	cout << "x, yには1000以下の正の実数を入力してください" <<endl;
	cout << "ex) 2.9 9.8" <<endl;
	cout << "披露を終了したい場合は負の数を入れてください" <<endl;
	while(1){
		cin >> x >> y;
		if(x < 0 || y < 0) break;
		if(mode == 0){
			if(x <= nmaxx && x >= nminx && y <= nmaxy && y >= nminy) cout << "ラベルは\"正\"です" <<endl;
			else cout << "ラベルは\"負\"です" <<endl;
		}
		else if(mode == 1){
			if(x <= pmaxx && x >= pminx && y <= pmaxy && y >= pminy) cout << "ラベルは\"正\"です" <<endl;
			else cout << "ラベルは\"負\"です" <<endl;
		}
	}
}