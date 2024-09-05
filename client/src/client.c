#include "client.h"
#include <readline/readline.h>

int main(void)
{

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger();
	log_info (logger,"Hola! Soy un log");


	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config();
	//ip = config_get_string_value(config, "IP");
	//puerto = config_get_string_value(config, "PUERTO");
	//valor = config_get_string_value(config, "CLAVE");

	//log_if_config_has_key(config, key)

	log_if_config_has_key(logger, config, "IP");
	log_if_config_has_key(logger, config, "PUERTO");
	log_if_config_has_key(logger, config, "CLAVE");



	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje

	// Armamos y enviamos el paquete
	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

t_log* iniciar_logger(void)
{	
	t_log* nuevo_logger = log_create("cliente.log","CL_logger", true, LOG_LEVEL_INFO);
	if(nuevo_logger == NULL){
		perror("No se pudo crear el log por algún error!");
		exit(EXIT_FAILURE);
	}
		return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config = config_create("cliente.config");		return nuevo_config;
	if(nuevo_config == NULL){
		perror("No se pudo crear el .config por algún error!");
		exit(EXIT_FAILURE);
	}
	return nuevo_config;
}

void log_if_config_has_key( t_log* logger,t_config* config, char* key)
{
	if(!config_has_property(config,key)){
		perror("El config no tiene la key");
		perror(key);
		exit(EXIT_FAILURE);
	}
	char* valor = config_get_string_value(config, key);
	log_info(logger, valor);
}

void leer_consola(t_log* logger)
{
	char* leido;

	// La primera te la dejo de yapa
	leido = readline("> ");

	// El resto, las vamos leyendo y logueando hasta recibir un string vacío


	// ¡No te olvides de liberar las lineas antes de regresar!

}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	log_destroy(logger);
	config_destroy(config);
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */
}
