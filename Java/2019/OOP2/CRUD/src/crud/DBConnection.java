package crud;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;
import java.util.ResourceBundle;

public class DBConnection {

    private static DBConnection instance = null;
    private Connection connection;
    private Statement statement;

    private DBConnection() {
        try {
            Class.forName(ResourceBundle.getBundle("crud/CRUD").getString("jdbc.driver")).newInstance();
            connection = DriverManager.getConnection(
                    ResourceBundle.getBundle("crud/CRUD").getString("jdbc.url"),
                    ResourceBundle.getBundle("crud/CRUD").getString("jdbc.user"),
                    ResourceBundle.getBundle("crud/CRUD").getString("jdbc.password"));
            statement = connection.createStatement();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    public Statement getStatement() {
        return statement;
    }

    public static DBConnection getInstance() {
        if (instance == null) {
            instance = new DBConnection();
        }
        return instance;
    }

    @Override
    protected void finalize() throws Throwable {
        statement.close();
        connection.close();
    }

}
