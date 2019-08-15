/**
 * @param {string[]} cpdomains
 * @return {string[]}
 */
 var subdomainVisits = function(cpdomains) {
  const map = new Map();
  let i = 0;
  cpdomains.forEach(record => {
    const [visitTime, domain] = record.split(" ");
    domain.split(".").reverse().reduce((dm, node) => {
      const key = (dm ? node + '.' + dm : node);
      const value = map.get(key);
      const count = parseInt(visitTime);
      if (!value) i++;
      map.set(key, !!value ? value + count : count);
      return key;
    }, '');
  });
  const list = Array(i);
  const entires = map.entries();
  for (const [k,v] of entires) {
    list[--i] = `${v} ${k}`
  }
  return list
};
