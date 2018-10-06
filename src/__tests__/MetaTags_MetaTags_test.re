open Jest;

open ExpectJs;
Testutils.configure();

module Make = (MetaTags: MetaTags.Interface) => {
  let setup = () => {
    module MetaTags = MetaTags_MetaTags.Make(MetaTags);
    Testutils.mount(<MetaTags />);
  };
};

let listItems = wrapper => wrapper |> Enzyme.Shallow.children;

describe("MetaTagsMetaTags", () =>
  test("render when only title is defined", () => {
    let title = "my title";
    module MetaTags =
      MetaTags.Make({});
    MetaTags.set_title(title);
    MetaTags.set_description("desc");
    module Context = Make(MetaTags);
    let wrapper = Context.setup();
    let expectedNode = <title> {ReasonReact.string(title)} </title>;
    expect(Enzyme.Shallow.contains(expectedNode, wrapper)) |> toBe(true);
  })
);