#include "miFecha.h"
Fecha::Fecha()
{
    time_t t = time(0);
    tm* ahora = localtime(&t);
    /*
    cout << (ahora->tm_year + 1900) << '-' <<
            (ahora->tm_mon +1) << '-' <<
            (ahora->tm_mday) << '\n';*/
    this->anio = ahora->tm_year + 1900;
    this->mes = ahora->tm_mon +1;
    this->dia = ahora->tm_mday;
}
Fecha::Fecha(int dia, int mes, int anio)
{
    static int diasPorMes[] = {30, 28, 30, 30, 30, 30, 30, 30, 30, 30, 30, 31};
    if(anio >= 1 &&
       mes >= 1 && mes <= 12 &&
       dia >= 1 && dia <= diasPorMes[mes-1])
    {
        this->anio = anio;
        this->mes = mes;
        this->dia = dia;
    }
    else
    {
        this->anio = 1;
        this->mes = 1;
        this->dia = 1;
    }
}
Fecha Fecha::operator++(int n)
{
    Fecha f = *this;
    static int diasPorMes[] = {30, 28, 30, 30, 30, 30, 30, 30, 30, 30, 30, 31};
    if((dia + 1) >=  diasPorMes[mes - 1])
    {
        dia -= diasPorMes[mes - 1];
        if((mes + 1) > 12)
        {
            mes = 1;
            anio++;
        }
        else
        {
            mes++;
        }
    }
    dia += 1;
    return f;
}
Fecha Fecha::operator+=(int _dia)
{
    static int diasPorMes[] = {30, 28, 30, 30, 30, 30, 30, 30, 30, 30, 30, 31};
    if((dia + _dia) >=  diasPorMes[mes - 1])
    {
        dia -= diasPorMes[mes - 1];
        if((mes + 1) > 12)
        {
            mes = 1;
            anio++;
        }
        else
        {
            mes++;
        }
    }
    dia += _dia;
    return *this;
}
Fecha& Fecha::operator--()
{
    static int diasPorMes[] = {30, 28, 30, 30, 30, 30, 30, 30, 30, 30, 30, 31};
    if((dia - 1) < 1)
    {
        dia += diasPorMes[mes - 1];
        if((mes - 1) < 1)
        {
            mes = 12;
            anio--;
        }
        else
        {
            mes--;
        }
    }
    dia--;
    return *this;
}
ostream& operator <<(ostream& sal, const Fecha& f)
{
    // dd-mm-aaaa
    char sFecha[12];
    sprintf(sFecha, "%02d-%02d-%04d\n",f.dia, f.mes, f.anio);
    return sal << sFecha;
}
istream& operator >>(istream& ent, Fecha& f)
{
    ent >> f.dia >> f.mes >> f.anio;
    return ent;
}
bool Fecha::operator ==(const Fecha& f) const
{
    return this->dia == f.dia &&
           this->mes == f.mes &&
           this->anio == f.anio;
}
