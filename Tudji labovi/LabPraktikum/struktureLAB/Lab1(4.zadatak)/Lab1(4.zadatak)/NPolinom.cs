using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1_4.zadatak_
{
    class NPolinom : IPolinom
    {
        private int s;
        private double[] nule;
        private int brNula;

        public NPolinom(int a, int x) 
        {
            s = a;
            brNula = x; 
            nule = new double[brNula];
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
            int proizvod = 1;
            for (int i = 0; i < brNula; i++) 
                proizvod = proizvod * (x - (int)nule[i]);
            return proizvod;

        }

        public int pronadjiNule(int g, int d, int x)
        {
            throw new NotImplementedException();
        }
    }
}
