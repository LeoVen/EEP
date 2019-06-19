package btt.dao;

import btt.model.ToDo;
import java.sql.Connection;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Calendar;


public class ToDoDAO {

    public static void add(Connection conn, String title, String desc, String category, Date date) throws SQLException {
        String query = "INSERT INTO todos (title, description, category, due) VALUES (?, ?, ?, ?);";

        try(PreparedStatement pStmt = conn.prepareStatement(query)) {
            pStmt.setString(1, title);
            pStmt.setString(2, desc);
            pStmt.setString(3, category);
            pStmt.setDate(4, date);

            pStmt.execute();
        }
    }

    public static ArrayList<ToDo> getFromCategory(Connection conn, String categoryName) throws SQLException {
        ArrayList<ToDo> list = new ArrayList<>();

        String query = "SELECT * FROM todos WHERE category = ?;";

        try (PreparedStatement pStmt = conn.prepareStatement(query)) {
            pStmt.setString(1, categoryName);

            ResultSet rs = pStmt.executeQuery();

            while (rs.next()) {
                int id = rs.getInt("id");
                String title = rs.getString("title");
                String description = rs.getString("description");
                String category = rs.getString("category");
                Date date = rs.getDate("due");
                Calendar cal = Calendar.getInstance();
                cal.setTime(date);
                list.add(new ToDo(id, title, description, category, cal));
            }
        }

        return list;
    }

    public static void update(Connection conn, int id, String title, String desc, String category, Date date) throws SQLException {
        String query = "UPDATE todos SET title = ?, description = ?, category = ?, due = ? WHERE id = ?;";

        try(PreparedStatement pStmt = conn.prepareStatement(query)) {
            pStmt.setString(1, title);
            pStmt.setString(2, desc);
            pStmt.setString(3, category);
            pStmt.setDate(4, date);
            pStmt.setInt(5, id);

            pStmt.execute();
        }
    }

    public static void delete(Connection conn, int id) throws SQLException {
        String query = "DELETE FROM todos WHERE id = ?;";

        try (PreparedStatement pStmt = conn.prepareStatement(query)) {
            pStmt.setInt(1, id);

            pStmt.execute();
        }
    }
}
