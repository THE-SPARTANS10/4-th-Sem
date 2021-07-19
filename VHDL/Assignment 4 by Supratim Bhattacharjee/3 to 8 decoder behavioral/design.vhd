library ieee;
use ieee.std_logic_1164.all;

entity decoder38 is
port(
  s: in std_logic_vector(2 downto 0);
  ac_high: out std_logic_vector(7 downto 0);
  ac_low: out std_logic_vector(7 downto 0));
end decoder38;

architecture behavioral of decoder38 is
begin
  process(s)
  begin
    case s is
      when "000" =>
        ac_high<="00000001";
        ac_low<= "11111110";
        
        when "001" =>
        ac_high<="00000010";
        ac_low<= "11111101";
        
        when "010" =>
        ac_high<="00000100";
        ac_low<= "11111011";
        
        when "011" =>
        ac_high<="00001000";
        ac_low<= "11110111";
        
        when "100" =>
        ac_high<="00010000";
        ac_low<= "11101111";
        
        when "101" =>
        ac_high<="00100000";
        ac_low<= "11011111";
        
        when "110" =>
        ac_high<="01000000";
        ac_low<= "10111111";
        
        when others =>
        ac_high<="10000000";
        ac_low<= "01111111";
    end case;
  end process;
end behavioral;