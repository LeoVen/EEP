<%-- 
    Document   : dictionary
    Created on : 04/11/2019, 03:10:05
    Author     : Leonardo Vencovsky (https://github.com/LeoVen/)
--%>

<%@ taglib uri="http://struts.apache.org/tags-bean" prefix="bean" %>
<%@ taglib uri="http://struts.apache.org/tags-html" prefix="html" %>
<%@ taglib uri="http://struts.apache.org/tags-logic" prefix="logic" %>

<%@page import="java.util.List"%>
<%@page import="eep.as.leoven.controller.PageContentController"%>
<%@page import="eep.as.leoven.dao.TranslationDAO"%>
<%@page import="eep.as.leoven.vo.Translation"%>
<%@page import="eep.as.leoven.vo.Word"%>

<%@page contentType="text/html"%>
<%@page pageEncoding="UTF-8"%>
<%@page errorPage="error.jsp" %>

<%
    // Prevent caching
    if (PageContentController.noCaching) {
        response.setDateHeader("Expires", 0);
    }

    List<Translation> translations = new TranslationDAO().getAll();
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

        <div class="centered-card">
            <div class="card">
                <div class="card-content">
                    <span class="card-title">Dictionary</span>
                    <div class="listing">
                        <ul class="collection">
                            <% for (Translation translation : translations) {%>
                            <%
                                Word word1 = translation.getWordByWord1();
                                Word word2 = translation.getWordByWord2();
                            %>
                            <li class="collection-item">
                                <span class="listingText"><%= word1.getWord()%></span>
                                <span class="listingText"><%= word2.getWord()%></span>
                                <a class="secondary-content">
                                    <i class="material-icons red-text">delete</i>
                                </a>
                            </li>
                            <% }%>
                        </ul>
                    </div>
                </div>
            </div>
        </div>

        <script src="https://code.jquery.com/jquery-3.4.1.min.js" integrity="sha256-CSXorXvZcTkaix6Yvo6HppcZGetbYMGWSFlBw8HfCJo=" crossorigin="anonymous"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/materialize/0.100.2/js/materialize.min.js"></script>
        <script src="js/main.js"></script>
    </body>
</html>
