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
    if(select_line="00") then
      output<=input(0);
    elsif(select_line="01") then
      output<=input(1);
    elsif(select_line="10") then
      output<=input(2);
    else
      output<=input(3);
    end if;
  end process;
end behavioral;