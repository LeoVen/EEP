package crud.dao;

import crud.DBConnection;
import crud.dao.i.ProdutoDAO;
import crud.vo.Produto;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

public class JDBCProdutoDAO implements ProdutoDAO {

    @Override
    public void create(Produto produto) throws Exception {
        DBConnection.getInstance().getStatement().executeUpdate("INSERT INTO produto VALUES(null,'"
                + produto.getNomeProduto() + "','"
                + produto.getPrecoProduto() + "',"
                + produto.getQuantidadeProduto() + ")");
    }

    @Override
    public List<Produto> retrieveAll() throws Exception {
        List<Produto> produtos = new ArrayList<>();
        ResultSet result = DBConnection.getInstance().getStatement().executeQuery("SELECT * FROM produto");

        while (result.next()) {
            Produto produto = new Produto(
                    result.getInt("id_produto"),
                    result.getString("nome_produto"),
                    result.getString("preco_produto"),
                    result.getInt("quantidade_produto"));
            produtos.add(produto);
        }

        return produtos;
    }

    @Override
    public Produto retrieveById(int idProduto) throws Exception {
        ResultSet result = DBConnection.getInstance().getStatement().executeQuery("SELECT * FROM produto WHERE id_produto = " + idProduto);

        if (result.next()) {
            return new Produto(
                    result.getInt("id_produto"),
                    result.getString("nome_produto"),
                    result.getString("preco_produto"),
                    result.getInt("quantidade_produto"));
        }
        return null;
    }

    @Override
    public void update(Produto produto) throws Exception {
        DBConnection.getInstance().getStatement().executeUpdate(
                "UPDATE produto SET nome_produto = '" + produto.getNomeProduto()
                + "', preco_produto = '" + produto.getPrecoProduto()
                + "',quantidade_produto = " + produto.getQuantidadeProduto()
                + " WHERE id_produto = " + produto.getIdProduto());
    }

    @Override
    public void delete(Produto produto) throws Exception {
        DBConnection.getInstance().getStatement().executeUpdate(
                "DELETE FROM produto WHERE id_produto = "
                + produto.getIdProduto());
    }
}
