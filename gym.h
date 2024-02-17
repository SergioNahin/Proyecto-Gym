#include <iostream>
#include <string>
using namespace std;

class gym{
	private:
		string nombre;
		string nombre_cliente;
		string password;
		int id,id_e,edad;
		string apellidoC,apellidoE,nombreE;
		float membre;
		
	public:
		
		void set_nombre(string nombre)
		{
			this->nombre=nombre;
		}
		string get_nombre()
		{
			return nombre;
		}
		void set_password(string password)
		{
			this->password=password;
		}
		string get_password()
		{
			return password;
		}
		
		//datos
		
			//nombre cliente
		void set_nombreC(string nombre_cliente)
		{
			this->nombre_cliente=nombre_cliente;
		}
		string get_nombreC()
		{
			return nombre_cliente;
		}
				//id
		void set_id(int id)
		{
			this->id=id;
		}
		int get_id()
		{
			return id;
		}
		
				//id
		void set_id_e(int id_e)
		{
			this->id_e=id_e;
		}
		int get_id_e()
		{
			return id_e;
		}
		
				//apellido cliente
		void set_apellidoC(string apellidoC)
		{
			this->apellidoC=apellidoC;
		}
		string get_apellidoC()
		{
			return apellidoC;
		}
				//nombre entrenador
		void set_nombreE(string nombreE)
		{
			this->nombreE=nombreE;
		}
		string get_nombreE()
		{
			return nombreE;
		}
		
				//apellido entrenador
		void set_apellidoE(string apellidoE)
		{
			this->apellidoE=apellidoE;
		}
		string get_apellidoE()
		{
			return apellidoE;
		}
		
				//membresia 
		void set_membre(float membre)
		{
			this->membre=membre;
		}
		float get_membre()
		{
			return membre;
		}
		
				//edad
		void set_edad(int edad)
		{
			this->edad=edad;
		}
		int get_edad()
		{
			return edad;
		}

};