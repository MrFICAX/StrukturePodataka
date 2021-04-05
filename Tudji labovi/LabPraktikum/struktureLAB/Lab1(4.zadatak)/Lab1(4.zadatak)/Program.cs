using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1_4.zadatak_
{
    class Program
    {
        static void Main(string[] args)
        {
            IPolinom p1 = new KPolinom(2);
            IPolinom p2 = new NPolinom(3,1);

            Console.WriteLine(p1.izracunajvrednost(1));
            Console.WriteLine(p2.izracunajvrednost(4));
     
            Console.WriteLine(p2.pronadjiNule(8, 4, 6));


        }
    }
}
