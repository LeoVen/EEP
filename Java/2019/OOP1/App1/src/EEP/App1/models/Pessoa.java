/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package EEP.App1.models;

import java.util.Date;

/**
 *
 * @author lvenk
 */
public class Pessoa {
    private String nome;
    private Date dataDeNascimento;
    private Double altura;
    
    public Pessoa(String nome) {
        this.nome = nome;
        this.dataDeNascimento = new Date();
        this.altura = 0.0;
    }

    public Pessoa(String nome, Date dataDeNascimento, Double altura) {
        this.nome = nome;
        this.dataDeNascimento = dataDeNascimento;
        this.altura = altura;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Date getDataDeNascimento() {
        return dataDeNascimento;
    }

    public void setDataDeNascimento(Date dataDeNascimento) {
        this.dataDeNascimento = dataDeNascimento;
    }

    public Double getAltura() {
        return altura;
    }

    public void setAltura(Double altura) {
        this.altura = altura;
    }

    @Override
    public String toString() {
        return "{ " + this.nome + ", " + this.dataDeNascimento.toString() + ", " + this.altura + " }";
    }
}
