using System;
using System.Data.SqlClient;

namespace DBConnection
{
    class DBConn
    {
        static void Main(string[] args)
        {
            using (var conn = new SqlConnection("Server=LDC3-24;Database=NORTHWND;" +
                "User Id=sa;Password=12345678;"))
            {
                try
                {
                    conn.Open();

                    Console.WriteLine("Conexão com sucesso");

                    var command = new SqlCommand("SELECT " +
                        "ProductId, ProductName, UnitPrice, " +
                        "( SELECT MAX(o.UnitPrice) FROM [Order Details] o" +
                        " WHERE o.ProductID = p.ProductId ) as MaxUnitPrice" +
                        " FROM Products p;");

                    command.Connection = conn;

                    SqlDataReader reader = command.ExecuteReader();

                    PrintDivider();

                    Console.WriteLine(String.Format(
                            "| {0,10} | {1,40} | {2,15} | {3,15} |",
                            "ProductId",
                            "ProductName",
                            "UnitPrice",
                            "MaxUnitPrice")
                    );

                    while (reader.Read())
                    {

                        PrintDivider();

                        Console.WriteLine(String.Format(
                            "| {0,10} | {1,40} | {2,15:C2} | {3,15:C2} |",
                            reader["ProductId"],
                            reader["ProductName"],
                            reader["UnitPrice"],
                            reader["MaxUnitPrice"]));
                    }

                    PrintDivider();
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

        static void PrintDivider()
        {
            Console.WriteLine("+------------+" +
                                "------------------------------------------+" +
                                "-----------------+" +
                                "-----------------+");
        }
    }
}
