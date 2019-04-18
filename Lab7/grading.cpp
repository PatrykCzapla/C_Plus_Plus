

// uzupe³nij
#include  "grading.h"


grading::grading()
{
	nota = 0;
	wsp_ceny = 1;
	firma_gradingowe = nullptr;
}
grading::grading(int nota, firma centrum ):nota(nota)
{
	if (centrum == BRAK)wsp_ceny = 1;
	if (centrum == Polskie_Centrum_Gradingu||centrum==Gliwickie_Centrum_Numizmatyczne)wsp_ceny = 1.25;
	if (centrum == Professional_Coin_Grading_Service||centrum==Numismatic_Guaranty_Corporation)wsp_ceny = 1.5;
	firma_gradingowe = new (nothrow) firma;
	*firma_gradingowe = centrum;
}
grading::grading(const grading& gr)
{
	nota = gr.nota;
	wsp_ceny = gr.wsp_ceny;
	firma_gradingowe = new (nothrow) firma;
	*firma_gradingowe = *(gr).firma_gradingowe;
}
grading::~grading()
{
	delete firma_gradingowe;
}
grading& grading::operator = (const grading& gr)
{
	if (this == &gr)return *this;
	nota = gr.nota;
	wsp_ceny = gr.wsp_ceny;
	delete firma_gradingowe;
	firma_gradingowe = new (nothrow) firma;
	*firma_gradingowe = *(gr).firma_gradingowe;
	return *this;
}
ostream& operator<<(ostream& out, const grading& gr)
{
	if (gr.firma_gradingowe == nullptr)
	{
		if (gr.nota < 45)
		{
			out << "stan obiegowy, " << "nota: " << gr.nota << endl;
		}
		if (gr.nota >= 45 && gr.nota < 60)
		{
			out << "stan okolomenniczy AU " << gr.nota << endl;
		}
		if (gr.nota >= 60 && gr.nota < 70) out << "stan menniczy MS " << gr.nota << endl;
		if (gr.nota == 70)out << "stan UNC " << gr.nota << endl;
		return out;
	}
	if (*(gr).firma_gradingowe == BRAK)
	{
		if (gr.nota < 45)
		{
			out << "stan obiegowy, " << "nota: " << gr.nota << endl;
		}
		if (gr.nota >= 45 && gr.nota < 60)
		{
			out << "stan okolomenniczy AU " << gr.nota << endl;
		}
		if (gr.nota >= 60 && gr.nota < 70) out << "stan menniczy MS " << gr.nota << endl;
		if (gr.nota == 70)out << "stan UNC " << gr.nota << endl;
		return out;
	}
	if (*(gr).firma_gradingowe == Polskie_Centrum_Gradingu)
	{
		if (gr.nota < 45)
		{
			out <<"PCG, stan obiegowy, " << "nota: " << gr.nota << endl;
		}
		if (gr.nota >= 45 && gr.nota < 60)
		{
			out << "PCG, stan okolomenniczy AU " << gr.nota << endl;
		}
		if (gr.nota >= 60 && gr.nota < 70) out << "PCG, stan menniczy MS " << gr.nota << endl;
		if (gr.nota == 70)out << "PCG, stan UNC " << gr.nota << endl;
		return out;
	}
	if (*(gr).firma_gradingowe == Gliwickie_Centrum_Numizmatyczne)
	{
		if (gr.nota < 45)
		{
			out << "GCN, stan obiegowy, " << "nota: " << gr.nota << endl;
		}
		if (gr.nota >= 45 && gr.nota < 60)
		{
			out << "GCN, stan okolomenniczy AU " << gr.nota << endl;
		}
		if (gr.nota >= 60 && gr.nota < 70) out << "GCN, stan menniczy MS " << gr.nota << endl;
		if (gr.nota == 70)out << "GCN, stan UNC " << gr.nota << endl;
		return out;
	}
	if (*(gr).firma_gradingowe == Professional_Coin_Grading_Service)
	{
		if (gr.nota < 45)
		{
			out << "PCGS, stan obiegowy, " << "nota: " << gr.nota << endl;
		}
		if (gr.nota >= 45 && gr.nota < 60)
		{
			out << "PCGS, stan okolomenniczy AU " << gr.nota << endl;
		}
		if (gr.nota >= 60 && gr.nota < 70) out << "PCGS, stan menniczy MS " << gr.nota << endl;
		if (gr.nota == 70)out << "PCGS, stan UNC " << gr.nota << endl;
		return out;
	}
	if (*(gr).firma_gradingowe == Numismatic_Guaranty_Corporation)
	{
		if (gr.nota < 45)
		{
			out << "NGC, stan obiegowy, " << "nota: " << gr.nota << endl;
		}
		if (gr.nota >= 45 && gr.nota < 60)
		{
			out << "NGC, stan okolomenniczy AU " << gr.nota << endl;
		}
		if (gr.nota >= 60 && gr.nota < 70) out << "NGC, stan menniczy MS " << gr.nota << endl;
		if (gr.nota == 70)out << "NGC, stan UNC " << gr.nota << endl;
		return out;
	}
}