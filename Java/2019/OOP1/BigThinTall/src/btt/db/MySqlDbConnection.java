/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package btt.db;

import com.mysql.cj.jdbc.MysqlDataSource;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Optional;

/**
 *
 * @author lvenk
 */
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
