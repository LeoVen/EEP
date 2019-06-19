package btt.db;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;


public class MySqlDbConnection {

    public static Connection getConnection() {

        // Connection URL
        String strConn = "jdbc:mysql://" + Macros.DbServerName + ":" + Macros.DbPort
                + "/" + Macros.DbDatabaseName + "?useTimezone=true&serverTimezone=UTC";

        try {
            // Get MySqlDriver Class
            Class.forName(Macros.MySqlDriver);

            Connection conn = DriverManager.getConnection(strConn, Macros.DbUsername, Macros.DbUserPassword);

            return conn;

        } catch (ClassNotFoundException e) {
            System.out.println("Class " + Macros.MySqlDriver + " not found");
            e.printStackTrace();
        } catch (SQLException e) {
            System.out.println("Could not connect to " + strConn);
            e.printStackTrace();
        }

        return null;
    }
}
