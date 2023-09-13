using System;
using Sys = Cosmos.System;

namespace Blint
{
    public class Kernel : Sys.Kernel
    {
        public static string version = "0.0.12923";
        protected override void BeforeRun()
        {
            Console.Clear();
            Console.WriteLine($"Blint version {version}");
        }

        protected override void Run()
        {
            Random random = new Random();
            var userGenerator = @$"Session{random.Next(1000, 9999)}";
            Console.Write(@$"
@-[ BLINT SESSION ]
|
@-[{userGenerator}]-> ");
            string read = Console.ReadLine();

            if (read == "getneon")
            {
                getNeon();
            }

            if (read == "poweroff")
            {
                Cosmos.System.Power.Shutdown();
            }
        }

        static void getNeon()
        {
            Neon82.Neon82.GetNeon();
        }
    }
}
