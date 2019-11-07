/*
 * The MIT License
 *
 * Copyright 2019 Leonardo Vencovsky (https://github.com/LeoVen/).
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
package eep.as.leoven.dao;

import eep.as.leoven.util.DbConnection;
import eep.as.leoven.vo.User;
import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.Transaction;

/**
 *
 * @author Leonardo Vencovsky (https://github.com/LeoVen/)
 */
public class UserDAO {

    /**
     * Creates a user in the database.
     *
     * @param user The user to be created in the database
     */
    public void create(User user) {
        Session session = null;
        Transaction transaction = null;
        try {
            session = DbConnection.getInstance().getSession();
            transaction = session.beginTransaction();

            session.save(user);
            session.flush();

            transaction.commit();
        } catch (HibernateException e) {
            if (transaction != null) {
                transaction.rollback();
            }
            throw e;
        } finally {
        }
    }

    /**
     * Checks if a pair of user name and password are present in the database.
     *
     * @param userName User name to be matched.
     * @param userPassword User password to be matched.
     *
     * @return Returns true if there is a user with a matching user name and
     * password.
     */
    public User match(String userName, String userPassword) {
        Session session = null;
        try {
            session = DbConnection.getInstance().getSession();

            Object obj = session.createQuery("from User u where u.name = '" + userName
                    + "' and u.password = '" + userPassword + "'").uniqueResult();

            if (obj != null) {
                return (User) obj;
            }

            session.flush();
        } catch (HibernateException e) {
            throw e;
        } finally {
        }

        return null;
    }

    /**
     * Returns true if the given user name already exists in the database,
     * otherwise false.
     *
     * @param name The name to be checked its existence in the database.
     *
     * @return Returns true if the user name already exists in the database, or
     * false if not.
     */
    public boolean contains(String name) {
        try {
            Session session = DbConnection.getInstance().getSession();

            Object obj = session.createQuery("from User u where u.name = '" + name + "'").uniqueResult();

            return obj != null;
        } catch (HibernateException e) {
            throw e;
        } finally {
        }
    }

}
