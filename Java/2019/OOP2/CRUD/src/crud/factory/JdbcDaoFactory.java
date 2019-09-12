package crud.factory;

import crud.dao.JdbcProdutoDao;
import crud.dao.i.IProdutoDao;

public class JdbcDaoFactory extends DaoAbstractFactory {

    @Override
    public IProdutoDao createProdutoDAO() {
        return new JdbcProdutoDao();
    }

}
