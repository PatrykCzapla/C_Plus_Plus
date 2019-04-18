#include <iostream>
using namespace std;
#include "waluta_francuska.h"

void sortuj_kwoty(waluta_francuska* kwoty, int size);
int main()
{
	cout << " ************************* Etap 1 (1,5 pkt) ************************* " << endl;
	waluta_francuska w0;				// 1.0.0
	waluta_francuska w1(-1.54);			// 0.0.0
	waluta_francuska w2(1.54);			// 1.10.10
	waluta_francuska w3(1, 30, 30);		// 2.12.6
	waluta_francuska w4(1, -30, 30);	// 0.0.0
	waluta_francuska w5(w3);			// 2.12.6
	waluta_francuska w6 = w2;			//1.10.10
	waluta_francuska w7;  
	cin >> w7;

	cout << "w0: " << w0 << "w1: " << w1 << "w2: " << w2 << "w3: " << w3 << "w4: " << w4 << "w5: " << w5 << "w6: " << w6 << "w7: " << w7;
	cout << endl;
	
	cout << " ************************* Etap 2 (1,5 pkt) ************************* " << endl;
	w1 = w3 - w2 - w1;
	cout << "w1 = w3 - w2 - w1: " << w1 << endl;
	w4 = w1 - w0;
	cout << "w4 = w1 - w0: " << w4 << endl;
	w4 += w3;
	cout << "w4 += w3: " << w4 << endl;
	cout << "2 * w6 * 2: " << 2 * w6 * 2;
	cout << endl;
	
	cout << " ************************* Etap 3 (1 pkt) ************************* " << endl;
	w7 = w4--;
	cout << "w7 = w4--: " << w7;
	--w4;
	cout << "--w4 (uzyte 2-krotnie): " << --w4;
	cout << " w4(): " << w4() << endl << endl;
	
	cout << " ************************* Etap 4 (2 pkt) ************************* " << endl;
	if (w6 == w2) cout << w6() << " jest rowne " << w2() << endl;
	if (w4 > w6) cout << w4() << " jest wieksze od " << w6() << endl;
	if (!(w6 > w2)) cout << w6() << " nie jest mniejsze od " << w2() << endl;
	cout << endl;
	

	const int size = 5;
	waluta_francuska kwoty[size] = { waluta_francuska(3,5,7), waluta_francuska(1,100,34), waluta_francuska(0,56,100), waluta_francuska(4,4,4), waluta_francuska(2,34,12) };
	cout << "Przed: " << endl;
	for (int i = 0; i < size; i++)
		cout << kwoty[i];
	sortuj_kwoty(kwoty, size);
	cout << "Po: " << endl;
	for (int i = 0; i < size; i++)
		cout << kwoty[i];
	system("pause");
	return 0;
}
void sortuj_kwoty(waluta_francuska* kwoty, int size)
{
	for(int i=0;i<size;i++)
		for (int j = 1; j < size; j++)
		{
			if (kwoty[j] > kwoty[j-1])
			{
				waluta_francuska a = kwoty[j];
				kwoty[j] = kwoty[j-1];
				kwoty[j - 1] = a;
			}
		}
}