package crud.dao.i;

import crud.vo.Produto;
import java.util.List;

public interface IProdutoDao {

    public void create(Produto produto) throws Exception;

    public List<Produto> retrieveAll() throws Exception;

    public Produto retrieveById(int idProduto) throws Exception;

    public void update(Produto produto) throws Exception;

    public void delete(Produto produto) throws Exception;
}
