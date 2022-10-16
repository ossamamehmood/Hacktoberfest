class CaesarCipher
  def cipher(message, shift, result = '')
    message.each_char do |char|
      base = char.ord < 91 ? 65 : 97
      if char.ord.between?(65, 90) ||char.ord.between?(97, 112)
        rotation = (((char.ord - base) + shift) % 26) + base
        result += rotation.chr
      else
        result += char
      end
    end
    result
  end
end

cc = CaesarCipher.new
# This would output: "Bmfy f xywnsl!"
cc.cipher(("What a string!", 5)
