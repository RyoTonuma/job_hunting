#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include"MT.h"

using namespace std;

//���O�̏o�͊֐�
void name(int i){
	if(i == 0){
		cout << "���\�Ђ�" << endl;
	}
	if(i == 1){
		cout << "�Y�߂�" << endl;
	}
	if(i == 2){
		cout << "�Y�߂�" << endl;
	}
	if(i == 3){
		cout << "�Y�߂�" << endl;
	}
	if(i == 4){
		cout << "�ߖ�" << endl;
	}
	if(i == 5){
		cout << "����" << endl;
	}
	if(i == 6){
		cout << "����" << endl;
	}
	if(i == 7){
		cout << "����" << endl;
	}
	if(i == 8){
		cout << "�n�ɖ�����" << endl;
	}
	if(i == 9){
		cout << "�ɉh" << endl;
	}
	if(i == 10){
		cout << "�����̒�" << endl;
	}
	if(i == 11){
		cout << "�슴" << endl;
	}
	if(i == 12){
		cout << "����" << endl;
	}
	if(i == 13){
		cout << "���e�I" << endl;
	}
	if(i == 14){
		cout << "���₹��" << endl;
	}
	if(i == 15){
		cout << "�u�a" << endl;
	}
	if(i == 16){
		cout << "�΍�Ђ�" << endl;
	}
	if(i == 17){
		cout << "�q�r��" << endl;
	}
	if(i == 18){
		cout << "�V�F�t�B�I��" << endl;
	}
	if(i == 19){
		cout << "�\��" << endl;
	}
	if(i == 20){
		cout << "��" << endl;
	}
	if(i == 21){
		cout << "�T" << endl;
	}
}

int main(){
	//�����̃V�[�h�ݒ�
	init_genrand((unsigned)time(NULL));
	//�V�F�t�B�̃t�B�[���h
	struct mount{
		int number;
		int rest;
	}sheep[7];
	int field[7];
	int enemysheep;
	int hand[5];
	int deck[22];
	int deckrest;
	int handnum;
	int deckmax;
	bool deathflag;
	int sheepnum;

	//�r�J�[�h�̕C�����`
	sheep[0].number = 1;
	sheep[1].number = 3;
	sheep[2].number = 10;
	sheep[3].number = 30;
	sheep[4].number = 100;
	sheep[5].number = 300;
	sheep[6].number = 1000;

	//�r�J�[�h�̖����̏�����
	for(int i=0;i<7;++i){
		sheep[i].rest = 7;
	}

	//�t�B�[���h�̏�����
	field[0] = 0;
	--sheep[0].rest;
	for(int i=1;i<7;++i){
		field[i] = -1;
	}
	sheepnum = 1;

	//��D�̏�����
	for(int i=0;i<5;++i){
		hand[i] = -1;
	}
	handnum = 0;

	//�R�D�̏�����
	for(int i=0;i<22;++i){
		deck[i] = 1;
	}
	deckrest = 22;

	//�G�r�̏�����
	enemysheep = 0;

	//�R�D�̏�����` �Ǖ��ɂ��ς��\�������邽��
	deckmax = 22;

	//���S�t���O�̏�����
	deathflag = false;

	while(!deathflag){
		while(1){

			//��ʂ̏�����
			std::system("cls");

			//�R�D����J�[�h���Ђ�

			int card;
			while(handnum < 5 && deckrest > 0){
				int nocard = -1;
				for(int i=0;i<5;++i){
					if(hand[i] == -1){
						nocard = i;
						break;
					}
				}

				card = genrand_int32() % deckrest +1;
				for(int i=0, j=0;i<card;++j){
					if(deck[j] == 1){
						++i;
					}
					if(i == card){
						deck[j] = 0;
						hand[nocard] = j;
						--deckrest;
						++handnum;
					}

				}
			}


			/*
			for(int i=0;i<5;++i){
			cout << "hand["<< i << "]="<< hand[i] << endl;
			}
			for(int i=0;i<22;++i){
			cout << "deck["<< i << "]="<< deck[i] << endl;
			}
			*/

			//�G�r�̕\��
			cout << "enemysheep : " << (int)pow(10,enemysheep) << endl;
			cout << endl;

			//�r�̎c�薇��
			for(int i=0;i<7;++i){
				cout << sheep[i].number << "�r : " << sheep[i].rest << "�C" << endl;
			}
			cout << endl;

			cout << "�t�B�[���h" << endl;
			//cout << "number : level" << endl;
			for(int i=0;i<7;++i){
				if(field[i] != -1){
					cout << i << " : " << sheep[field[i]].number << " sheep" << endl;
				}
			}
			cout << endl;

			//�J�[�h�̎g�p
			cout << "Use card." << endl;
			for(int i=0;i<5;++i){
				if(hand[i] != -1){
					cout << i << " : ";
					name(hand[i]);
				}
			}
			int choice = -1;
			cin >> choice;
			int selectcard;
			selectcard = hand[choice];
			hand[choice] = -1;
			--handnum;

			//�e�X�̃J�[�h�̏���

			// 00: All-purpose Sheep
			if(selectcard == 0){
				cout << "Choose card." << endl;
				for(int i=0;i<5;++i){
					if(hand[i] != -1){
						cout << i << " : ";
						name(hand[i]);
					}
				}
				cin >> choice;
				selectcard = hand[choice];
			}

			// 01: Be Fruitful
			if(selectcard == 1){
				if(sheepnum != 7){
					cout << "Choose sheep card." << endl;
					for(int i=0;i<7;++i){
						if(field[i] != -1){
							cout << i << " : " << sheep[field[i]].number << " sheep" << endl;
						}
					}
					int copy;
					cin >> copy;
					cout << "Choose empty field." << endl;
					for(int i=0;i<7;++i){
						if(field[i] == -1){
							cout << i << endl;
						}
					}
					int efield;
					cin >> efield;
					field[efield] = field[copy];
					--sheep[field[efield]].rest;
					++sheepnum;
				}
			}

			// 02: Be Fruitful
			if(selectcard == 2){
				if(sheepnum != 7){
					cout << "Choose sheep card." << endl;
					for(int i=0;i<7;++i){
						if(field[i] != -1){
							cout << i << " : " << sheep[field[i]].number << " sheep" << endl;
						}
					}
					int copy;
					cin >> copy;
					cout << "Choose empty field." << endl;
					for(int i=0;i<7;++i){
						if(field[i] == -1){
							cout << i << endl;
						}
					}
					int efield;
					cin >> efield;
					field[efield] = field[copy];
					--sheep[field[efield]].rest;
					++sheepnum;
				}
			}

			// 03: Be Fruitful
			if(selectcard == 3){
				if(sheepnum != 7){
					cout << "Choose sheep card." << endl;
					for(int i=0;i<7;++i){
						if(field[i] != -1){
							cout << i << " : " << sheep[field[i]].number << " sheep" << endl;
						}
					}
					int copy;
					cin >> copy;
					cout << "Choose empty field." << endl;
					for(int i=0;i<7;++i){
						if(field[i] == -1){
							cout << i << endl;
						}
					}
					int efield;
					cin >> efield;
					field[efield] = field[copy];
					--sheep[field[efield]].rest;
					++sheepnum;
				}
			}

			// 04: Crowding
			if(selectcard == 4){
				while(sheepnum > 2){
					cout << "Choose sheep card." << endl;
					for(int i=0;i<7;++i){
						if(field[i] != -1){
							cout << i << " : " << sheep[field[i]].number << " sheep" << endl;
						}
					}
					int ssheep;
					cin >> ssheep;
					++sheep[field[ssheep]].rest;
					field[ssheep] = -1;
					--sheepnum;

				}
			}

			// 05: Dominion
			if(selectcard == 5){
				int sheepsum = 0;
				while(1){
					cout << "Choose sheep card." << endl;
					cout << "Finish : -1" << endl;
					cout << "sum : " << sheepsum << endl;
					for(int i=0;i<7;++i){
						if(field[i] != -1){
							cout << i << " : " << sheep[field[i]].number << " sheep" << endl;
						}
					}
					int ssheep;
					cin >> ssheep;
					if(ssheep == -1){
						int domsheep;
						cout << "Choose the kind of sheep." << endl;
						for(int i=0;i<7&&sheep[i].number<=sheepsum;++i){
							cout << i << " : " << sheep[i].number << endl;
						}
						cin >> domsheep;
						cout << "Choose empty field." << endl;
						for(int i=0;i<7;++i){
							if(field[i] == -1){
								cout << i << endl;
							}
						}
						int efield;
						cin >> efield;
						field[efield] = domsheep;
						--sheep[domsheep].rest;
						++sheepnum;
						break;
					}
					sheepsum += sheep[field[ssheep]].number;
					++sheep[field[ssheep]].rest;
					field[ssheep] = -1;
					--sheepnum;
				}

			}

			// 06: Dominion
			if(selectcard == 6){
				int sheepsum = 0;
				while(1){
					cout << "Choose sheep card." << endl;
					cout << "Finish : -1" << endl;
					cout << "sum : " << sheepsum << endl;
					for(int i=0;i<7;++i){
						if(field[i] != -1){
							cout << i << " : " << sheep[field[i]].number << " sheep" << endl;
						}
					}
					int ssheep;
					cin >> ssheep;
					if(ssheep == -1){
						int domsheep;
						cout << "Choose the kind of sheep." << endl;
						for(int i=0;i<7&&sheep[i].number<=sheepsum;++i){
							cout << i << " : " << sheep[i].number << endl;
						}
						cin >> domsheep;
						cout << "Choose empty field." << endl;
						for(int i=0;i<7;++i){
							if(field[i] == -1){
								cout << i << endl;
							}
						}
						int efield;
						cin >> efield;
						field[efield] = domsheep;
						--sheep[domsheep].rest;
						++sheepnum;
						break;
					}
					sheepsum += sheep[field[ssheep]].number;
					++sheep[field[ssheep]].rest;
					field[ssheep] = -1;
					--sheepnum;
				}
			}

			// 07: Falling Rock
			if(selectcard == 7){
				cout << "Choose sheep card." << endl;
				for(int i=0;i<7;++i){
					if(field[i] != -1){
						cout << i << " : " << sheep[field[i]].number << " sheep" << endl;
					}
				}
				int ssheep;
				cin >> ssheep;
				++sheep[field[ssheep]].rest;
				field[ssheep] = -1;
				--sheepnum;
			}

			// 08: Fill the Earth
			if(selectcard == 8){
				while(1){
					cout << "Choose empty field." << endl;
					cout << "Finish : -1" << endl;
					for(int i=0;i<7;++i){
						if(field[i] == -1){
							cout << i << endl;
						}
					}
					int efield;
					cin >> efield;
					if(efield == -1){
						break;
					}
					field[efield] = 0;
					--sheep[0].rest;
					++sheepnum;
				}
			}

			// 09: Flourish
			if(selectcard == 9){
				cout << "Choose sheep card." << endl;
				for(int i=0;i<7;++i){
					if(field[i] != -1){
						cout << i << " : " << sheep[field[i]].number << " sheep" << endl;
					}
				}
				int ssheep;
				cin >> ssheep;
				if(field[ssheep] != 0){
					for(int i=0;i<3 && sheepnum!=7;++i){
						cout << "Choose empty field." << endl;
						for(int j=0;j<7;++j){
							if(field[j] == -1){
								cout << j << endl;
							}
						}
						int efield;
						cin >> efield;
						field[efield] = field[ssheep] - 1;
						--sheep[ssheep].rest;
						++sheepnum;
					}
				}
			}

			// 10: Golden Hooves
			if(selectcard == 10){
				int garray[7] = {0};
				int maxsheep = 0;
				for(int i=0;i<7;++i){
					if(maxsheep < field[i]){
						maxsheep = field[i];
					}
				}
				while(1){
					cout << "Choose sheep card." << endl;
					cout << "Finish : -1" << endl;
					for(int i=0;i<7;++i){
						if(field[i] != -1 && field[i] < maxsheep && garray[i] == 0){
							cout << i << " : " << sheep[field[i]].number << " sheep" << endl;
						}
					}
					int ssheep;
					cin >> ssheep;
					garray[ssheep] = 1;
					if(ssheep == -1){
						break;
					}
				}
				for(int i=0;i<7;++i){
					if(garray[i] == 1){
						++sheep[field[i]].rest;
						++field[i];
						--sheep[field[i]].rest;
					}
				}
			}

			// 11: Inspiration
			if(selectcard == 11){
				cout << "Choose card." << endl;
				for(int i=0;i<22;++i){
					if(deck[i] == 1){
						cout << i << " : " ;
						name(i);
					}
				}
				int scard;
				cin >> scard;
				hand[choice] = scard;
				deck[scard] = 0;
				--deckrest;
				++handnum;
			}

			// 12: Lightning
			if(selectcard == 12){
				int maxsheep = 0;
				for(int i=0;i<7;++i){
					if(maxsheep < field[i]){
						maxsheep = field[i];
					}
				}
				cout << "Choose sheep card." << endl;
				for(int i=0;i<7;++i){
					if(maxsheep == field[i]){
						cout << i << " : " << sheep[field[i]].number << " sheep" << endl;
					}
				}
				int ssheep;
				cin >> ssheep;
				++sheep[field[ssheep]].rest;
				field[ssheep] = -1;
				--sheepnum;
			}

			// 13: Meteor
			if(selectcard == 13){
				for(int i=0;i<3&&sheepnum>0;++i){
					cout << "Choose sheep card." << endl;
					for(int j=0;j<7;++j){
						if(field[j] != -1){
							cout << j << " : " << sheep[field[j]].number << " sheep" << endl;
						}
					}
					int ssheep;
					cin >> ssheep;
					++sheep[field[ssheep]].rest;
					field[ssheep] = -1;
					--sheepnum;
				}
				deck[13] = -1;
				--deckmax;
			}

			// 14: Multiply
			if(selectcard == 14){
				if(sheepnum != 7){
					cout << "Choose empty field." << endl;
					for(int i=0;i<7;++i){
						if(field[i] == -1){
							cout << i << endl;
						}
					}
					int efield;
					cin >> efield;
					field[efield] = 1;
					--sheep[1].rest;
					++sheepnum;
				}
			}

			// 15: Plague
			if(selectcard == 15){
				cout << "Choose the kind of sheep." << endl;
				for(int i=0;i<7;++i){
					if(sheep[i].rest != 7){
						cout << i << " : " << sheep[i].number << endl;
					}
				}
				int sksheep;
				cin >> sksheep;
				for(int i=0;i<7;++i){
					if(field[i] == sksheep){
						++sheep[field[i]].rest;
						field[i] = -1;
						--sheepnum;
					}
				}
			}

			// 16: Planning Sheep
			if(selectcard == 16){
				cout << "Choose card." << endl;
				for(int i=0;i<5;++i){
					if(hand[i] != -1){
						cout << i << " : " ;
						name(hand[i]);
					}
				}
				int discard;
				cin >> discard;
				deck[hand[discard]] = -1;
				hand[discard] = -1;
				--handnum;
				--deckmax;
			}

			// 17: Sheep Dog
			if(selectcard == 17){
				cout << "Choose card." << endl;
				for(int i=0;i<5;++i){
					if(hand[i] != -1){
						cout << i << " : " ;
						name(hand[i]);
					}
				}
				int discard;
				cin >> discard;
				hand[discard] = -1;
				--handnum;

			}

			// 18: Shephion
			if(selectcard == 18){
				for(int i=0;i<7;++i){
					if(field[i] != -1){
						++sheep[field[i]].rest;
						field[i] = -1;
						--sheepnum;
					}
				}
			}
			// 19: Slump
			if(selectcard == 19){
				int tcardnum=sheepnum / 2;
				for(int i=0;i<tcardnum;++i){
					cout << "Choose sheep card." << endl;
					for(int j=0;j<7;++j){
						if(field[j] != -1){
							cout << j << " : " << sheep[field[j]].number << " sheep" << endl;
						}
					}
					int ssheep;
					cin >> ssheep;
					++sheep[field[ssheep]].rest;
					field[ssheep] = -1;
					--sheepnum;
				}
			}

			// 20: Storm
			if(selectcard == 20){
				for(int i=0;i<2&&sheepnum>0;++i){
					cout << "Choose sheep card." << endl;
					for(int j=0;j<7;++j){
						if(field[j] != -1){
							cout << j << " : " << sheep[field[j]].number << " sheep" << endl;
						}
					}
					int ssheep;
					cin >> ssheep;
					++sheep[field[ssheep]].rest;
					field[ssheep] = -1;
					--sheepnum;
				}
				deck[20] = -1;
				--deckmax;
			}

			// 21: Wolves
			if(selectcard == 21){
				int maxsheep = 0;
				for(int i=0;i<7;++i){
					if(maxsheep < field[i]){
						maxsheep = field[i];
					}
				}
				cout << "Choose sheep card." << endl;
				for(int i=0;i<7;++i){
					if(maxsheep == field[i]){
						cout << i << " : " << sheep[field[i]].number << " sheep" << endl;
					}
				}

				int ssheep;
				cin >> ssheep;
				++sheep[field[ssheep]].rest;
				--field[ssheep];
				--sheep[field[ssheep]].rest;
			}


			/*
			for(int i=0;i<5;++i){
			cout << "hand["<< i << "]="<< hand[i] << endl;
			}
			for(int i=0;i<22;++i){
			cout << "deck["<< i << "]="<< deck[i] << endl;
			}
			*/
			if(handnum == 0 || sheepnum == 0) break;
		}
		++enemysheep;
		if(enemysheep >=3 || sheepnum <= 0){
			deathflag = true;
		}
		if(deathflag){
			cout << "Game Over" << endl;
		}
		
		for(int i=0;i<22;++i){
			if(deck[i] != -1){
				deck[i] = 1;
			}
		}
		deckrest = deckmax;
	}

	return 0;
}