package crud.dao;

import crud.dao.i.ProdutoDAO;
import crud.vo.Produto;
import java.util.List;
import net.sf.ehcache.hibernate.HibernateUtil;
import org.hibernate.Session;
import org.hibernate.Transaction;

public class HibernateProdutoDAO implements ProdutoDAO {

    @Override
    public void create(Produto produto) {
        Session session = HibernateUtil.getSessionFactory().openSession();
        Transaction transaction = session.beginTransaction();
        session.save(produto);
        session.flush();
        transaction.commit();
        session.close();
    }

    @Override
    public List<Produto> retrieveAll() {
        Session session = HibernateUtil.getSessionFactory().openSession();
        List<Produto> produtos = session.createQuery("from Produto").list();
        session.flush();
        session.close();
        return produtos;
    }

    @Override
    public Produto retrieveById(int idProduto) {
        Session session = HibernateUtil.getSessionFactory().openSession();
        Produto produto = (Produto) session.createQuery(
                "from Produto where idProduto = " + idProduto).uniqueResult();
        session.flush();
        session.close();
        return produto;
    }

    @Override
    public void delete(Produto produto) {
        Session session = HibernateUtil.getSessionFactory().openSession();
        Transaction transaction = session.beginTransaction();
        session.delete(produto);
        session.flush();
        transaction.commit();
        session.close();
    }

    @Override
    public void update(Produto produto) {
        Session session = HibernateUtil.getSessionFactory().openSession();
        Transaction transaction = session.beginTransaction();
        session.update(produto);
        session.flush();
        transaction.commit();
        session.close();
    }
}
