#ifndef GCC_SOURCEMANAGER_HPP
#define GCC_SOURCEMANAGER_HPP
#include <filesystem>
#include <string>
#include <string_view>
#include <vector>

#include "SourceLocation.hpp"
#include "gcc/lexer/Token.hpp"

/**
 * Administra el código fuente de un archivo.
 *
 * SourceManager es el propietario del texto fuente y proporciona acceso
 * eficiente a su contenido y a la información de localización asociada.
 *
 * Sus responsabilidades incluyen:
 * - Cargar el código fuente desde un archivo o una cadena.
 * - Almacenar el contenido durante toda la compilación.
 * - Proporcionar acceso al texto mediante std::string_view.
 * - Convertir desplazamientos (offsets) en línea y columna.
 * - Obtener información sobre el archivo fuente.
 *
 * Esta clase no realiza análisis léxico, sintáctico ni semántico; su única
 * responsabilidad es administrar el texto fuente y su correspondencia con
 * posiciones dentro del archivo.
 */

/**
 * Manages the source code of a file.
 *
 * The SourceManager owns the source text and provides efficient access to its
 * contents and source location information.
 *
 * Its responsibilities include:
 * - Loading source code from a file or an in-memory string.
 * - Owning the source text for the lifetime of the compilation.
 * - Providing read-only access to the source through std::string_view.
 * - Mapping character offsets to line and column numbers.
 * - Exposing file and source information to other compiler components.
 *
 * SourceManager is a utility class only. It performs no lexical, syntactic,
 * or semantic analysis.
 */

class SourceManager {
public:
    explicit SourceManager(std::filesystem::path );
    explicit SourceManager(std::string);

    std::filesystem::path path() const noexcept;
    std::string filename() const;
    std::string_view source() const;
    std::size_t size() const noexcept;
    bool empty() const noexcept;
    char operator[](std::size_t offset) const noexcept;
    bool isValidOffset(std::size_t offset) const noexcept;
    SourceLocation location(std::size_t offset) const;
    std::string_view line(std::size_t lineNumber) const;
    std::string_view lexeme(const Token& token) const;

private:
    std::filesystem::path path_;
    std::string source_;
    std::vector<std::size_t> lineOffsets_;

    void buildLineTable();
    std::string readFile(const std::filesystem::path&) const;

};

#endif //GCC_SOURCEMANAGER_HPP
