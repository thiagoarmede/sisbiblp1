#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include "estruturas.h"


//funções genéricas

void destroy_janela(GtkButton *b, GtkWindow *w){
   gtk_widget_hide_on_delete(GTK_WIDGET(w));
}
void destroy_janela2(GtkWindow *w){
   gtk_widget_hide_on_delete(GTK_WIDGET(w));
}
void on_botao_clicked_open_window (GtkButton *b, GtkWindow *w){
    gtk_widget_show_all(GTK_WIDGET(w));
}

//funções na janela inicial de login em particular 

void on_janela_login_destroy(GtkWindow *w){
    gtk_main_quit();
}

//funções janela sobre em particular

void abrir_sobre(GtkMenuItem *m, GtkAboutDialog *w){
	gtk_widget_show_all(GTK_WIDGET(w));
}
void on_janela_sobre_destroy (GtkAboutDialog *w){
	gtk_widget_hide_on_delete(GTK_WIDGET(w));
}

//funções janela chave em particular

void on_botao_ok_chave_clicked(GtkButton *b, GtkWidget *aux[]){
    char chave[20] = "123456";
    GtkWindow *jcadastro, *jerro;
    GtkEntry *ent;

    jcadastro = aux[0];
    jerro = aux[1];
    ent = aux[2];

    if(strcmp(chave, gtk_entry_get_text(GTK_ENTRY(ent)))){
        gtk_widget_show_all(GTK_WIDGET(jerro));
    }else{
        gtk_widget_show_all(GTK_WIDGET(jcadastro));
    }
}


void on_botao_cadastrar_cadastro_clicked(GtkButton *b, GtkWiget w[]){
	GtkEntry *nome, *usuario, *senha, *datanasc, *datacad, *email, *rg, *cpf;
	FILE *fd1 = fopen("bibliotecarios.bin","wb");
	BIBLIOTECARIO b;
	/*typedef struct{
    	char nome[100];
    	char RG[10];
    	char CPF[12];
    	char email[50];
    	DATA data_nasc, data_cadastro;
    	char usuario[50], senha[50];
	}BIBLIOTECARIO;*/
	nome = GTK_ENTRY(w[0]);
	usuario = GTK_ENTRY(w[1]);
	senha = GTK_ENTRY (w[2]);
	datanasc = GTK_ENTRY(w[3]);
	rg = GTK_ENTRY(w[4]);
	datacad = GTK_ENTRY(w[5]);
	cpf = GTK_ENTRY(w[6]);
	email = GTK_ENTRY(w[7]);

	strcpy(b.nome, gtk_entry_get_text(nome));
	strcpy(b.RG, gtk_entry_get_text(RG));
	strcpy(b.CPF, gtk_entry_get_text(CPF));
	strcpy(b.usuario, gtk_entry_get_text(usuario));
	strcpy(b.senha, gtk_entry_get_text(senha));
	strcpy(b.email, gtk_entry_get_text(email));









}


int main(int argc, char *argv[]){

    ////////////////////Declaração de variáveis////////////////
    //builder
    GtkBuilder *builder;
    //Janelas
    GtkWindow *janela_cadastro, *janela_aviso, *janela_chave, *janela_login, *janela_erro_chave;
    GtkAboutDialog *janela_sobre;
    //Entradas Tela de Login
    GtkEntry *entrada_usuario, *entrada_senha;
    //Entrada Tela de chave
    GtkEntry *entrada_chave;
    //Entradas Tela de cadastro
    GtkEntry *entrada_nome_cadastro, *entrada_datanasc_cadastro, *entrada_usuario_cadastro, *entrada_cpf_cadastro,
    *entrada_senha_cadastro, *entrada_email_cadastro, *entrada_datacad_cadastro, *entrada_rg_cadastro;
    //Botões tela de login
    GtkButton *botao_entrar;
    GtkCheckButton *check_lembrar;
    GtkButton *botao_cadastro;
    //Botões tela de chave
    GtkButton *botao_ok_chave;
    GtkButton *botao_cancelar_chave;
    //Botão tela de aviso
    GtkButton *botao_ok_aviso_cadastro;
    //Botões tela de cadastro
    GtkButton *botao_cadastrar_cadastro;
    GtkButton *botao_voltar_cadastro;
    //Botão tela de erro chave
    GtkButton *botao_ok_erro_chave;
    //Botões tela sobre


    //Itens de menu da tela sobre
    GtkMenuItem *menu_sobre_login;


    //Vetores de widgets auxiliares 
    GtkWidget *widgetsaux[3], *widgetscadastro[15];

    //////////////////////Fim da declaração de variáveis////////////////

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder,"SisbibUI.glade", NULL);

    ///////////////Atribuindo objetos do builder às variáveis////////////////
    //janelas
    janela_cadastro = GTK_WINDOW(gtk_builder_get_object(builder, "janela_cadastro"));
    janela_aviso = GTK_WINDOW(gtk_builder_get_object(builder, "janela_aviso"));
    janela_chave = GTK_WINDOW(gtk_builder_get_object(builder, "janela_chave"));
    janela_login = GTK_WINDOW(gtk_builder_get_object(builder, "janela_login"));
    janela_erro_chave = GTK_WINDOW(gtk_builder_get_object(builder, "janela_erro_chave"));
    janela_sobre = GTK_ABOUT_DIALOG(gtk_builder_get_object(builder, "janela_sobre"));
    //entradas
    entrada_usuario = GTK_ENTRY(gtk_builder_get_object(builder, "entrada_usuario"));
    entrada_senha = GTK_ENTRY(gtk_builder_get_object(builder, "entrada_senha"));
    entrada_chave = GTK_ENTRY(gtk_builder_get_object(builder, "entrada_chave"));
    entrada_nome_cadastro = GTK_ENTRY(gtk_builder_get_object(builder, "entrada_nome_cadastro"));
    entrada_datanasc_cadastro = GTK_ENTRY(gtk_builder_get_object(builder, "entrada_datanasc_cadastro"));
    entrada_usuario_cadastro = GTK_ENTRY(gtk_builder_get_object(builder, "entrada_usuario_cadastro"));
    entrada_cpf_cadastro = GTK_ENTRY(gtk_builder_get_object(builder, "entrada_cpf_cadastro"));
    entrada_senha_cadastro = GTK_ENTRY(gtk_builder_get_object(builder, "entrada_senha_cadastro"));
    entrada_email_cadastro = GTK_ENTRY(gtk_builder_get_object(builder, "entrada_email_cadastro"));
    entrada_datacad_cadastro = GTK_ENTRY(gtk_builder_get_object(builder, "entrada_datacad_cadastro"));
    entrada_rg_cadastro = GTK_ENTRY(gtk_builder_get_object(builder, "entrada_rg_cadastro"));
    //botões
    botao_entrar = GTK_BUTTON(gtk_builder_get_object(builder, "botao_entrar"));
    check_lembrar = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "check_lembrar"));
    botao_cadastro = GTK_BUTTON(gtk_builder_get_object(builder, "botao_cadastro"));
    botao_ok_chave = GTK_BUTTON(gtk_builder_get_object(builder, "botao_ok_chave"));
    botao_cancelar_chave = GTK_BUTTON(gtk_builder_get_object(builder, "botao_cancelar_chave"));
    botao_ok_aviso_cadastro = GTK_BUTTON(gtk_builder_get_object(builder, "botao_ok_aviso_cadastro"));
    botao_cadastrar_cadastro = GTK_BUTTON(gtk_builder_get_object(builder, "botao_cadastrar_cadastro"));
    botao_voltar_cadastro = GTK_BUTTON(gtk_builder_get_object(builder, "botao_voltar_cadastro"));
    botao_ok_erro_chave = GTK_BUTTON(gtk_builder_get_object(builder, "botao_ok_erro_chave"));
    //items de menu
    menu_sobre_login = GTK_MENU_ITEM(gtk_builder_get_object(builder,"menu_sobre_login"));




    //Sinais tela de login
    g_signal_connect(janela_login, "destroy", G_CALLBACK(on_janela_login_destroy),NULL);
    g_signal_connect(botao_cadastro, "clicked", G_CALLBACK(on_botao_clicked_open_window), janela_chave);
    //Sinais tela de chave
    widgetsaux[0]=janela_cadastro;    
    widgetsaux[1]=janela_erro_chave; 
    widgetsaux[2]=entrada_chave;
    g_signal_connect(botao_ok_chave, "clicked", G_CALLBACK(on_botao_ok_chave_clicked), widgetsaux);
    g_signal_connect(botao_ok_chave, "clicked", G_CALLBACK(destroy_janela),janela_chave);
    g_signal_connect(janela_chave,"delete-event", G_CALLBACK(destroy_janela2),NULL);
    //Sinais tela de erro
    g_signal_connect(botao_ok_erro_chave, "clicked", G_CALLBACK(destroy_janela),janela_erro_chave);
    g_signal_connect(janela_erro_chave,"delete-event", G_CALLBACK(destroy_janela2),NULL);
    //Sinais tela sobre
    g_signal_connect(menu_sobre_login,"activate", G_CALLBACK(abrir_sobre), janela_sobre);
    g_signal_connect(janela_sobre,"delete-event", G_CALLBACK(on_janela_sobre_destroy), NULL);
    //Sinais tela de cadastro
    widgetscadastro[0] = GTK_WIDGET(entrada_nome_cadastro);
    widgetscadastro[1] = GTK_WIDGET(entrada_usuario_cadastro;
    widgetscadastro[2] = GTK_WIDGET(entrada_senha_cadastro);
    widgetscadastro[3] = GTK_WIDGET(entrada_datanasc_cadastro);
    widgetscadastro[4] = GTK_WIDGET(entrada_rg_cadastro);
    widgetscadastro[5] = GTK_WIDGET(entrada_datacad_cadastro);
    widgetscadastro[6] = GTK_WIDGET(entrada_cpf_cadastro);
    widgetscadastro[7] = GTK_WIDGET(entrada_email_cadastro);
    g_signal_connect(botao_cadastrar_cadastro, "clicked", G_CALLBACK(on_botao_cadastrar_cadastro_clicked), widgetscadastro);

    //comandos finais e loop do programa
    gtk_widget_show_all(GTK_WIDGET(janela_login));
    

    g_object_unref(builder);

    gtk_main();
    
    return 0;
}

