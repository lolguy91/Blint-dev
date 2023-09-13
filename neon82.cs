using System;
using Blint;

namespace Neon82
{
    public class Neon82
    {
        public static void GetNeon()
        {
            Console.ForegroundColor = ConsoleColor.DarkMagenta;
            Console.Write("###########   ");
            Console.ForegroundColor = ConsoleColor.White;
            Console.Write($"Blint version {Blint.Kernel.version}\n");
            Console.ForegroundColor = ConsoleColor.DarkMagenta;
            Console.WriteLine("  ####   ###");
            Console.WriteLine("    ##   ###");
            Console.WriteLine("    #######");
            Console.WriteLine("    ##   ###");
            Console.WriteLine("    ##   ###");
            Console.WriteLine("    #######");
            Console.ForegroundColor = ConsoleColor.White;
            Console.ResetColor();
        }
    }
}
