using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1_4.zadatak_
{
    class KPolinom : IPolinom
    {
        private int s;
        private int[] niz;
        public KPolinom(int a)
        {
            s = a;
            niz = new int[a + 1];
        }

        public int X
        {
            get
            {
                return this.s;
            }
        }

        public int izracunajvrednost(int x)
        {
            int p = 0;
            for (int i = 0; i < s; i++)
            {
                p = p + (niz[i] * (int)Math.Pow(x, i));
            }
            return p;
        }
        public int pronadjiNule(int g, int d, int x)
        {
            int sr = 0;
            sr = (g + d) / 2;
            while (Math.Abs((g - d) / 2) > x)
            {
                int p = izracunajvrednost(sr);
                if (g * p > 0)
                    g = sr;
                else
                    d = sr;
            }
            return sr;
        }
        public void Stampaj()
        {
            for (int i = 0; i < s; i++)
            {
                Console.Write(niz[i] + "x^" + i + "  ");

            }
            Console.WriteLine(" ");
        }
        int IPolinom.pronadjiNule(int a, int b, int x)
        {
            throw new NotImplementedException();
        }
    }
}
