library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity fa is
port(
  A: in std_logic;
  B: in std_logic;
  Cin: in std_logic;
  S: out std_logic;
  Cout: out std_logic;
  );
end fa;

architecture behavioral of fa is
  begin
  process(A,B,Cin)
    begin
	  if(A<='0' and B<='0' and Cin<='0') then
        S<='0';
        Cout<='0';
      elsif(A<='0' and B<='0' and Cin<='1') then
        S<='1';
        Cout<='0';
      elsif(A<='0' and B<='1' and Cin<='0') then
        S<='1';
        Cout<='0';
      elsif(A<='0' and B<='1' and Cin<='1') then
        S<='0';
        Cout<='1';
      elsif(A<='1' and B<='0' and Cin<='0') then
        S<='1';
        Cout<='0';
      elsif(A<='1' and B<='0' and Cin<='1') then
        S<='0';
        Cout<='1';
      elsif(A<='1' and B<='1' and Cin<='0') then
        S<='0';
        Cout<='1';
      else
        S<='1';
        Cout<='1';
      end if;
  end process;
end behavioral;