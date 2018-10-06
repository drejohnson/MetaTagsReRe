[@bs.module "enzyme"] external mount: Enzyme.node => Enzyme.Shallow.t = "";
let configure = () => Enzyme.configureEnzyme(Enzyme.react_16_adapter());