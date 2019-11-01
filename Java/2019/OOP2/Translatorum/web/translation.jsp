<%-- 
    Document   : translation.jsp
    Created on : 31/10/2019, 20:09:49
    Author     : Leonardo Vencovsky (https://github.com/LeoVen/)
--%>

<%@page import="eep.as.leoven.dao.WordDAO"%>
<%@page import="java.util.List"%>
<%@page import="eep.as.leoven.vo.Word"%>
<%@ taglib uri="http://struts.apache.org/tags-bean" prefix="bean" %>
<%@ taglib uri="http://struts.apache.org/tags-html" prefix="html" %>
<%@ taglib uri="http://struts.apache.org/tags-logic" prefix="logic" %>

<%@page import="eep.as.leoven.vo.Language"%>
<%@page import="eep.as.leoven.controller.PageContentController"%>

<%@page contentType="text/html"%>
<%@page pageEncoding="UTF-8"%>
<%@page errorPage="error.jsp" %>

<%
    // Prevent caching
    if (PageContentController.noCaching) {
        response.setDateHeader("Expires", 0);
    }

    Language lang1 = PageContentController.getTranslationLanguage1();
    Language lang2 = PageContentController.getTranslationLanguage2();

    WordDAO wordDao = new WordDAO();

    List<Word> words1 = wordDao.getByLanguage(lang1);
    List<Word> words2 = wordDao.getByLanguage(lang2);
%>

<!DOCTYPE html>
<html>
    <head>
        <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/materialize/0.100.2/css/materialize.min.css">
        <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
        <link rel="stylesheet" href="${pageContext.request.contextPath}/css/main.css" type="text/css" >
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

        <h3><%= lang1.getName()%></h3>
        <h3><%= lang2.getName()%></h3>
        <script src="https://code.jquery.com/jquery-3.4.1.min.js" integrity="sha256-CSXorXvZcTkaix6Yvo6HppcZGetbYMGWSFlBw8HfCJo=" crossorigin="anonymous"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/materialize/0.100.2/js/materialize.min.js"></script>
        <script src="js/main.js"></script>
    </body>
</html>
