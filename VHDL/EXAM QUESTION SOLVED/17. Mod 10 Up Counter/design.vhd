library IEEE;
use IEEE.std_logic_1164.all;

entity TFF is
port(
  T,PRE,RST,CLK: in std_logic; q: out std_logic);
end TFF;

architecture rtl of TFF is
begin
  process(T,PRE,RST,CLK)
  begin
    if(PRE='1' and RST='1') then q<='X';--PRE and RST are active high
    elsif(RST='1') then q<='0'; 
    elsif(PRE='1') then q<='1'; 
    elsif(CLK' event and CLK='1' and T='1') then q<=not q;--clk active high
   	end if;
  end process;
end rtl;

-----------------------------------------------------------------

library IEEE;
use IEEE.std_logic_1164.all;

entity asyn_3_bit_upcntr is
port(PRE,RST,CLK: in std_logic; Q: out std_logic_vector(3 downto 0));
end entity;

architecture rtl2 of asyn_3_bit_upcntr is

component TFF is
port(
  T,PRE,RST,CLK: in std_logic; q: out std_logic);
end component;
begin
  O1: TFF port map('1',PRE,RST,CLK,Q(0));
  O2: TFF port map('1',PRE,RST,not Q(0),Q(1));
  O3: TFF port map('1',PRE,RST,not Q(1),Q(2));
  O4: TFF port map('1',PRE,RST,not Q(2),Q(3));
end rtl2;