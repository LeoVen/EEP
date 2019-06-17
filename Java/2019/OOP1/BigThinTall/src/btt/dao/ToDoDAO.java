/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package btt.dao;

import btt.model.ToDo;
import java.sql.Connection;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

/**
 *
 * @author lvenk
 */
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
                list.add(new ToDo(id, title, description, category, date));
            }
        }

        return list;
    }
}
