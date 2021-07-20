library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity dff_async_reset is
port(
  D: in std_logic;
  clk: in std_logic;
  reset: in std_logic;
  O: out std_logic
  );
end dff_async_reset;

architecture behavioral of dff_async_reset is
begin
  process(D,clk,reset)
  begin
    if(reset='1') then
      O<='0';
    elsif(clk'event and clk='1') then
      O<=D;
    end if;
  end process;
end behavioral;