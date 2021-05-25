using System;
using System.IO;
namespace RemoveMetaFile
{
    class Program
    {
        
        static void Main(string[] args)
        {
            string path = Directory.GetParent(Directory.GetCurrentDirectory()).FullName;
            if (!Directory.Exists(path + @"\RemoveOnly"))
            {
                Console.WriteLine("-------------  CreateRemoveFolder  -------------");
                Directory.CreateDirectory(path + @"\RemoveOnly");
            }

            Console.WriteLine("-------------  Search & Move  -------------");
            FileSearch(path, path + @"\RemoveOnly");

            Console.WriteLine("-------------  Remove  -------------");
            Directory.Delete(path + @"\RemoveOnly", true);
            Console.WriteLine("-------------  Done!  -------------");
            Console.WriteLine("Press Any Key...");
            Console.ReadKey();
        }
        static void FileSearch(string path, string Removepath)
        {
            if(path == Removepath) { Console.WriteLine("RemoveOnlyFolder"); return; }
            string[] files = Directory.GetFiles(path, "*.meta");
            string[] directories = Directory.GetDirectories(path);
            if(directories.Length != 0)
            {
                foreach (string a in directories)
                {
                    FileSearch(a, Removepath);
                }
                
            }
            Console.WriteLine("Folder : " + path + "  --------------------");
            foreach (string a in files)
            {
                Console.WriteLine(a.Substring(path.Length+1));
                File.Move(a, Removepath + a.Substring(path.Length));
                if (File.Exists(path + @"\Wobble.cs"))
                {
                    Console.WriteLine("Wobble.cs");
                    File.Move(path + @"\Wobble.cs", Removepath + @"\Wobble.cs");
                }

            }
            Console.WriteLine("");
        }
    }
}
