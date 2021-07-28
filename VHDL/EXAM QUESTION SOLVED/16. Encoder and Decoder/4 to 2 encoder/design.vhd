library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity encoder42 is
port(
  I0: in std_logic;
  I1: in std_logic;
  I2: in std_logic;
  I3: in std_logic;
  O0: out std_logic;
  O1: out std_logic;
  );
end encoder42;

architecture behavioral of encoder42 is
  begin
  process(I0,I1,I2,I3)
    begin
	  if(I0='1' and I1='0' and I2='0' and I3='0') then
        O0<='0';
        O1<='0';
      elsif(I0='0' and I1='1' and I2='0' and I3='0') then
        O0<='1';
        O1<='0';
      elsif(I0='0' and I1='0' and I2='1' and I3='0') then
        O0<='0';
        O1<='1';
      else
        O0<='1';
        O1<='1';
      end if;
  end process;
end behavioral;
