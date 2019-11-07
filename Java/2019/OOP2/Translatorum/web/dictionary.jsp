<%-- 
    Document   : dictionary
    Created on : 04/11/2019, 03:10:05
    Author     : Leonardo Vencovsky (https://github.com/LeoVen/)
--%>

<%@page import="eep.as.leoven.util.DbConnection"%>
<%@ taglib uri="http://struts.apache.org/tags-bean" prefix="bean" %>
<%@ taglib uri="http://struts.apache.org/tags-html" prefix="html" %>
<%@ taglib uri="http://struts.apache.org/tags-logic" prefix="logic" %>

<%@page import="java.util.List"%>
<%@page import="eep.as.leoven.controller.ApplicationController"%>
<%@page import="eep.as.leoven.dao.TranslationDAO"%>
<%@page import="eep.as.leoven.vo.Translation"%>
<%@page import="eep.as.leoven.vo.Word"%>

<%@page contentType="text/html"%>
<%@page pageEncoding="UTF-8"%>
<%@page errorPage="error.jsp" %>

<%
    // Check user login
    if (ApplicationController.getCurrentUser() == null) {
        response.sendRedirect("unauthorized.jsp");
    }

    // Prevent caching
    if (ApplicationController.isNoCaching()) {
        response.setDateHeader("Expires", 0);
    }

    DbConnection.getInstance().getSession().clear();

    List<Translation> translations = new TranslationDAO().getAll();
%>

<!DOCTYPE html>
<html>
    <head>
        <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
        <link rel="stylesheet" href="css/materialize.css">
        <link rel="stylesheet" href="css/main.css">
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Translatorum</title>
    </head>
    <body>
        <!-- FAB -->
        <div class="fixed-action-btn">
            <a href="index.jsp" class="btn-floating btn-large orange">
                <i class="larg material-icons">keyboard_return</i>
            </a>
        </div>

        <div class="centered-card">
            <div class="card">
                <div class="card-content">
                    <span class="card-title">Dictionary</span>
                    <div class="listing">
                        <table>
                            <tbody>
                                <% for (Translation translation : translations) {%>
                                <%
                                    Word word1 = translation.getWordByWord1();
                                    Word word2 = translation.getWordByWord2();
                                %>
                                <tr>
                                    <td>
                                        <span class="listingText card-title"><%= word1.getWord()%></span>
                                        <p class="listingText subheader"><%= word1.getLanguage().getName()%></p>
                                    </td>
                                    <td>
                                        <span class="listingText card-title"><%= word2.getWord()%></span>
                                        <p class="listingText"><%= word2.getLanguage().getName()%></p>
                                    </td>
                                    <td>
                                        <a href="javascript:deleteTranslationSelection(<%= translation.getId()%>)">
                                            <i class="material-icons red-text">delete</i>
                                        </a>
                                    </td>
                                </tr>
                                <% }%>
                            </tbody>
                        </table>
                    </div>
                </div>
            </div>
        </div>

        <div class="display-none">
            <html:form action="DeleteTranslation">
                <html:text styleId="deleteTranslationId" name="DeleteTranslationActionForm" property="translationId"/>
                <html:submit styleId="deleteTranslationSubmit" />
            </html:form>
        </div>

        <script src="js/jquery-3.4.1.js"></script>
        <script src="js/materialize.js"></script>
        <script src="js/main.js"></script>
    </body>
</html>
