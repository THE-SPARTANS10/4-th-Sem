library ieee;
use ieee.std_logic_1164.all;

entity mux41 is
port(
  input: in std_logic_vector(3 downto 0);
  select_line: in std_logic_vector(1 downto 0);
  output: out std_logic);
end mux41;

architecture behavioral of mux41 is
begin
  process(input,select_line)
  begin
    case select_line is
      when "00" =>
        output<=input(0);
      when "01" =>
        output<=input(1);
      when "10" =>
        output<=input(2);
      when others =>
        output<=input(3);
    end case;
  end process;
end behavioral;