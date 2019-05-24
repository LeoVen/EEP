/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package btt.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.TreeMap;

/**
 *
 * @author lvenk
 */
public class CategoryDAO {

    public static TreeMap<String, Integer> getAll(Connection conn, int userId) throws SQLException {
        TreeMap<String, Integer> categories = new TreeMap<>();

        String query = "SELECT * FROM categories WHERE userid = ?;";

        try(PreparedStatement pStmt = conn.prepareStatement(query)) {
            pStmt.setInt(1, userId);

            try(ResultSet rs = pStmt.executeQuery()) {
                while (rs.next()) {
                    categories.put(rs.getString("name"), rs.getInt("id"));
                }
            }
        }

        return categories;
    }

    public static boolean contains(Connection conn, int userId, String categoryName) throws SQLException {
        String query = "SELECT * FROM categories WHERE userid = ? AND name = ?;";

        try(PreparedStatement pStmt = conn.prepareStatement(query)) {
            pStmt.setInt(1, userId);
            pStmt.setString(2, categoryName);

            try(ResultSet rs = pStmt.executeQuery()) {
                return rs.next();
            }
        }
    }

    public static void add(Connection conn, int userId, String categoryName) throws SQLException {
        String query = "INSERT INTO categories (userid, name) VALUES (?, ?);";

        try(PreparedStatement pStmt = conn.prepareStatement(query)) {
            pStmt.setInt(1, userId);
            pStmt.setString(2, categoryName);

            pStmt.execute();
        }
    }

    public static void delete(Connection conn, int userId, String categoryName) throws SQLException {
        String query = "DELETE FROM categories WHERE userid = ? AND name = ?;";

        try(PreparedStatement pStmt = conn.prepareStatement(query)) {
            pStmt.setInt(1, userId);
            pStmt.setString(2, categoryName);

            pStmt.execute();
        }
    }
}
