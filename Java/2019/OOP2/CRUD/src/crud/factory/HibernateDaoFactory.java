package crud.factory;

import crud.dao.HibernateProdutoDao;
import crud.dao.i.IProdutoDao;

public class HibernateDaoFactory extends DaoAbstractFactory {

    @Override
    public IProdutoDao createProdutoDAO() {
        return new HibernateProdutoDao();
    }

}
