// Mostrar u ocultar opciones de corrimiento
document.getElementById("conversion-type").addEventListener("change", function () {
    const type = this.value;
    const corrimientoOptions = document.getElementById("corrimiento-options");
    if (type === "corrimiento") {
      corrimientoOptions.style.display = "block";
    } else {
      corrimientoOptions.style.display = "none";
    }
  });
  
  // Manejar el botón de conversión
  document.getElementById("convert-button").addEventListener("click", function () {
    const inputValue = document.getElementById("input-value").value.trim();
    const conversionType = document.getElementById("conversion-type").value;
  
    let result = "";
  
    try {
      switch (conversionType) {
        case "bin-to-dec":
          validar_binario(inputValue);
          result = `Decimal: ${binario_a_decimal(inputValue)}`;
          break;
        case "bin-to-hex":
          validar_binario(inputValue);
          result = `Hexadecimal: ${binario_a_hexadecimal(inputValue)}`;
          break;
        case "dec-to-hex":
          validar_decimal(inputValue);
          result = `Hexadecimal: ${decimal_a_hexadecimal(parseInt(inputValue))}`;
          break;
        case "hex-to-dec":
          validar_hexadecimal(inputValue);
          result = `Decimal: ${hexadecimal_a_decimal(inputValue)}`;
          break;
        case "corrimiento":
          validar_binario(inputValue);
          const direccion = document.getElementById("corrimiento-dir").value;
          const posiciones = parseInt(
            document.getElementById("corrimiento-steps").value
          );
          validar_posiciones(posiciones);
          result = `Resultado: ${corrimiento_binario(
            inputValue,
            direccion,
            posiciones
          )}`;
          break;
        default:
          result = "Conversión no soportada.";
      }
    } catch (error) {
      result = `Error: ${error.message}`;
    }
  
    // Mostrar resultado
    document.getElementById("result-output").innerText = result;
    if (result.startsWith("Error")) {
      alert(result); // Mostrar alarma si ocurre un error
    }
  });
  
  // Funciones de Validación
  function validar_binario(binario) {
    if (!/^[01]+$/.test(binario)) {
      throw new Error("El número ingresado no es un binario válido.");
    }
  }
  
  function validar_decimal(decimal) {
    if (!/^\d+$/.test(decimal)) {
      throw new Error("El número ingresado no es un decimal válido.");
    }
  }
  
  function validar_hexadecimal(hexadecimal) {
    if (!/^[0-9A-Fa-f]+$/.test(hexadecimal)) {
      throw new Error("El número ingresado no es un hexadecimal válido.");
    }
  }
  
  function validar_posiciones(posiciones) {
    if (isNaN(posiciones) || posiciones < 1) {
      throw new Error("El número de posiciones debe ser mayor a 0.");
    }
  }
  
  // Funciones Simuladas para Conversiones
  
  function binario_a_decimal(binario) {
    return parseInt(binario, 2);
  }
  
  function binario_a_hexadecimal(binario) {
    const decimal = binario_a_decimal(binario);
    return decimal.toString(16).toUpperCase();
  }
  
  function decimal_a_hexadecimal(decimal) {
    return decimal.toString(16).toUpperCase();
  }
  
  function hexadecimal_a_decimal(hexadecimal) {
    return parseInt(hexadecimal, 16);
  }
  
  function corrimiento_binario(binario, direccion, posiciones) {
    let numero = parseInt(binario, 2); // Convertir binario a decimal
    const longitud_original = binario.length;
  
    if (direccion === "I") {
      numero <<= posiciones; // Corrimiento a la izquierda
      // Limitar la longitud para que no se pierdan cifras
      const mascara = (1 << longitud_original) - 1;
      numero &= mascara;
    } else if (direccion === "D") {
      numero >>= posiciones; // Corrimiento a la derecha
    } else {
      throw new Error("Dirección de corrimiento no válida.");
    }
  
    // Convertir de vuelta a binario y rellenar con ceros si es necesario
    return numero.toString(2).padStart(longitud_original, "0");
  }
  