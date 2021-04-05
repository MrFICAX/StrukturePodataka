using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1_4.zadatak_
{
    interface IPolinom
    {
        int  izracunajvrednost(int x);
        int   pronadjiNule(int a, int b, int x);
        int X { get; }
    }
}
