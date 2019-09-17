package edu.eep.leoven.currencyconvert;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    // Contém os elementos da tela e faz o carregamento uma única vez e pode ser usado a qualquer momento
    private ViewHolder mViewHolder = new ViewHolder();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Busca os elementos da interface
        this.mViewHolder.editValue = findViewById(R.id.edit_real);
        this.mViewHolder.textDolar = findViewById(R.id.text_dollar);
        this.mViewHolder.buttonCalculate = findViewById(R.id.button_calculate);

        // Adiciona evento de click no elemento
        this.mViewHolder.buttonCalculate.setOnClickListener(this);

        // Limpa os valores iniciais
        this.clearValues();
    }

    @Override
    public void onClick(View view) {
        // Verifica se o elemento clicado é o que nos interessa
        if (view.getId() == R.id.button_calculate) {
            //Mostra mensagem para o usuário
            String value = mViewHolder.editValue.getText().toString();
            if ("".equals(value)) {
                Toast.makeText(this, this.getString(R.string.digitar_valor), Toast.LENGTH_LONG).show();
            } else {
                // Converte o valor informado
                Double real = Double.valueOf(value);
                this.mViewHolder.textDolar.setText(String.format("%.2f", real / 4));
            }
        }
    }

    //Limpa os valores iniciais
    private void clearValues() {
        this.mViewHolder.textDolar.setText("");
    }

    //Padrão ViewHolder
    private static class ViewHolder {
        EditText editValue;
        TextView textDolar;
        Button buttonCalculate;
    }
}
