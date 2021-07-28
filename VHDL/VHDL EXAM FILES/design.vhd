library ieee;
use ieee.std_logic_1164.all;

entity siso_3_bit is
port(
  inp: in std_logic;
  clk: in std_logic;
  q3: out std_logic;
  q2: out std_logic;
  q1: out std_logic
);
end siso_3_bit;

architecture structural of siso_3_bit is

component dff is
port(
  d: in std_logic;
  ck: in std_logic;
  q: out std_logic
);
end component;

begin
  ff3: dff port map(inp,clk,q3);
  ff2: dff port map(q3,clk,q2);
  ff1: dff port map(q2,clk,q1);

end structural;

-------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

entity dff is
port(
  d: in std_logic;
  ck: in std_logic;
  q: out std_logic
);
end dff;

architecture behavioral of dff is
begin
  process(d,ck)
  begin
    if(ck'event and ck='1') then
		q<=d;
    end if;
  end process;
end behavioral;