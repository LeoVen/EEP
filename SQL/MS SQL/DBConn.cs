using System;
using System.Data.SqlClient;

namespace DBConnection
{
    class DBConn
    {
        static void Main(string[] args)
        {
            using (var conn = new SqlConnection("Server=LDC3-24;Database=NORTHWND;User Id=sa;Password=12345678;"))
            {
                try
                {
                    conn.Open();

                    Console.WriteLine("Conexão com sucesso");

                    var command = new SqlCommand("select * from Products;");

                    command.Connection = conn;

                    SqlDataReader reader = command.ExecuteReader();

                    while (reader.Read())
                    {
                        Console.WriteLine($"{reader["ProductId"]} {reader["ProductName"]}");
                    }
                }
                catch (SqlException e)
                {
                    Console.WriteLine(e.Message);
                    Console.WriteLine(e.StackTrace);
                }
                finally
                {
                    conn.Close();
                    Console.WriteLine("Fechando a conexão");
                }
            }
            
            Console.ReadKey();
        }
    }
}
