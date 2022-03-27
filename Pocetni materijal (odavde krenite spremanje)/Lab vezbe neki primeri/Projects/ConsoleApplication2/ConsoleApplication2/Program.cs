using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Oracle.DataAccess.Client;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
            OracleConnection con = null;
            string conString = "Data Source = 160.99.9.199/gislab.elfak.ni.ac.rs; User Id = S14432; Password = S14432;";
            try
            {
                //korisnik sa tastature unosi tip filmova
                Console.WriteLine("Uneti tip za koji zelite da odredite broj filmova");
                string tip = Console.ReadLine();

                //otvaramo konekciju ka bazi podataka
                con = new OracleConnection(conString);
                con.Open();

                //pripremamo komandu koja ce za zadati tip odrediti broj filmova
                string strSQL = "SELECT COUNT(*) FROM FILM WHERE TIP = '" + tip + "'";

                OracleCommand cmd = new OracleCommand(strSQL, con);
                cmd.CommandType = System.Data.CommandType.Text;

                //izvrsavamo komandu i prihvatamo skalarnu vrednost
                decimal brojFilmova = (decimal)cmd.ExecuteScalar();

                //Stampamo pribavljenu informaciju
                Console.WriteLine("Za zadati tip u bazi postoji " + brojFilmova.ToString() + " filmova!");

            }
            catch (Exception ec)
            {
                Console.WriteLine("Doslo je do greske prilikom pristupanja bazi podataka: " + ec.Message);
            }
            finally
            {
                if (con != null && con.State == System.Data.ConnectionState.Open)
                    con.Close();

                con = null;
            }
        }
    }
}