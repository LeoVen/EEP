package crud.factory;

import crud.dao.i.IProdutoDao;

public abstract class DaoAbstractFactory {

    public static final int JDBC = 1;
    public static final int HIBERNATE = 2;

    public abstract IProdutoDao createProdutoDAO();

    public static DaoAbstractFactory getFactory(int factoryType) {
        if (factoryType == JDBC) {
            return new JdbcDaoFactory();
        } else if (factoryType == HIBERNATE) {
            return new HibernateDaoFactory();
        }

        throw new IllegalArgumentException("No matching factory type for id " + factoryType);
    }
}
