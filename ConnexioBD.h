#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <map>

class ConnexioBD2 {
private:
    std::string server;
    std::string port;
    std::string user;
    std::string password;
    std::string database;

    void llegeixConfiguracio() {
        std::string fileconf = "config.conf";
        std::ifstream file(fileconf);

        if (!file.is_open()) {
            throw std::runtime_error("No s'ha pogut obrir l'arxiu de configuració: " + fileconf);
        }

        std::map<std::string, std::string> config;
        std::string line;

        while (std::getline(file, line)) {
            // Ignorar líneas vacías o comentarios
            if (line.empty() || line[0] == '#') continue;

            size_t pos = line.find('=');
            if (pos == std::string::npos) {
                throw std::runtime_error("Format invàlid al fitxer de configuració: " + line);
            }

            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
            config[key] = value;
        }

        file.close();

        // Asignar valores desde el mapa
        server = config["server"];
        port = config["port"];
        user = config["user"];
        password = config["password"];
        database = config["database"];
    }

public:
    ConnexioBD2() {
        llegeixConfiguracio();
    }

    void mostrarConfiguracio() {
        std::cout << "Server: " << server << "\n"
            << "Port: " << port << "\n"
            << "User: " << user << "\n"
            << "Password: " << password << "\n"
            << "Database: " << database << "\n";
    }

    // Aquí irían los métodos para conectarse a la base de datos
};

