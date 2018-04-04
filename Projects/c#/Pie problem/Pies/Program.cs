using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;

namespace Pies
{
    class Program
    {
         static void Main(string[] args)
        {
            var file= new FileStream(@"file.txt", FileMode.Open, FileAccess.Read);
            using (var Reader = new StreamReader(file, Encoding.UTF8))
            {
                string line;
                while ((line =Reader.ReadLine()) != null)
                {
                    Console.WriteLine(MaxPie(line)); 
                    // process the line
                }
            }



        }
        static string  MaxPie(string line) {
            int aPie = 0;
            int pPie = 0;
            List<int> numbers = new List<int>(Array.ConvertAll(line.Split(','), int.Parse));

            while (numbers[1] >= 1 && numbers[2] >= 4 && numbers[3] >= 3 && numbers[4] >= 2)
            {
                numbers[1] -= 1; numbers[2] -= 4; numbers[3] -= 3; numbers[4] -= 2;
                aPie += 1;
            }

            while (numbers[0]>=1&& numbers[2] >= 3 && numbers[3] >= 4 && numbers[4] >= 3)
            {
                numbers[0] -= 1;numbers[2] -= 3; numbers[3] -= 4; numbers[4] -= 3;
                pPie += 1;
            }
           
           



            return "You can make " + pPie + " pumpkin pies and " + aPie + " apple pies";
        }
    }
}
